// Copyright © 2019 진준호. All rights reserved.

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct Edge
{
    int to, weight;
};

int n, start, target;
std::vector<Edge> adj[10001];

bool canCarry(int load)
{
    std::vector<char> visited(n + 1, false);
    std::queue<int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        if(node == target)
        {
            return true;
        }
        for(auto [next, weight] : adj[node])
        {
            if(!visited[next] && weight >= load)
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, maxWeight = -1;
    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int from, to, weight;
        std::cin >> from >> to >> weight;
        maxWeight = std::max(maxWeight, weight);
        adj[from].push_back({to, weight});
        adj[to].push_back({from, weight});
    }
    std::cin >> start >> target;
    int left = 1, right = maxWeight;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(canCarry(mid))
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    std::cout << right << '\n';
    return 0;
}
