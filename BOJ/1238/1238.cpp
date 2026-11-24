// Copyright © 2020 진준호. All rights reserved.

#include <algorithm>
#include <iostream>
#include <vector>

constexpr int INF = 2147000;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, x;
    std::cin >> n >> m >> x;
    std::vector<std::vector<int>> dist(n + 1, std::vector<int>(n + 1, INF));
    for(int i = 0; i < m; i++)
    {
        int from, to, cost;
        std::cin >> from >> to >> cost;
        dist[from][to] = cost;
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int maxRoundTrip = -1;
    for(int i = 1; i <= n; i++)
    {
        if(i == x || dist[i][x] == INF || dist[x][i] == INF)
        {
            continue;
        }
        maxRoundTrip = std::max(maxRoundTrip, dist[i][x] + dist[x][i]);
    }
    std::cout << maxRoundTrip << '\n';
    return 0;
}
