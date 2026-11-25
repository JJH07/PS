// Copyright © 2020 진준호. All rights reserved.

#include <functional>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, start;
    std::cin >> n >> m >> start;
    std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
    for(int i = 0; i < m; i++)
    {
        int from, to, weight;
        std::cin >> from >> to >> weight;
        adj[from].push_back({to, weight});
    }

    constexpr int INF = std::numeric_limits<int>::max();
    std::vector<int> dist(n + 1, INF);
    using Entry = std::pair<int, int>;
    std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();
        if(cost != dist[node])
        {
            continue;
        }
        for(auto [next, weight] : adj[node])
        {
            const int nextCost = cost + weight;
            if(nextCost < dist[next])
            {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }
    for(int node = 1; node <= n; node++)
    {
        if(dist[node] == INF)
        {
            std::cout << "INF\n";
        }
        else
        {
            std::cout << dist[node] << '\n';
        }
    }
    return 0;
}
