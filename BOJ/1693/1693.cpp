// Copyright © 2020 진준호. All rights reserved.

#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <cstring>

int n, dp[100001][31], maxColor;
std::vector<int> adj[100001];
int minCost(int node, int parent, int color)
{
    if(node > 1 && (int)adj[node].size() == 1)
    {
        return color;
    }
    int &cost = dp[node][color];
    if(cost != -1)
    {
        return cost;
    }
    cost = color;
    for(auto it = adj[node].begin(); it != adj[node].end(); it++)
    {
        if(*it == parent)
        {
            continue;
        }
        int bestChild = INT_MAX;
        for(int i = 1; i <= maxColor; i++)
        {
            if(color == i)
            {
                continue;
            }
            bestChild = std::min(bestChild, minCost(*it, node, i));
        }
        cost += bestChild;
    }
    return cost;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::memset(dp, -1, sizeof(dp));

    std::cin >> n;
    maxColor = (int)log2(n);
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        std::cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = INT_MAX;
    for(int i = 1; i <= maxColor; i++)
    {
        ans = std::min(ans, minCost(1, 0, i));
    }
    std::cout << ans << '\n';
    std::cout << '\n' << (int)log2(100001) << '\n';
    return 0;
}
