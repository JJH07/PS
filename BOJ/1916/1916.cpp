// Copyright © 2020 진준호. All rights reserved.

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    constexpr int INF = 2147000000;
    int n, m, start, target;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
    for(int i = 0; i < m; i++)
    {
        int from, to, cost;
        std::cin >> from >> to >> cost;
        adj[from].push_back({to, cost});
    }
    std::cin >> start >> target;

    std::vector<int> dist(n + 1, INF);
    using Entry = std::pair<int, int>;
    std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();
        if(cost > dist[node])
        {
            continue;
        }
        if(node == target)
        {
            break;
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
    std::cout << dist[target] << '\n';
    return 0;
}
