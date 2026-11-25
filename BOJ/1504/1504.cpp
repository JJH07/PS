// Copyright © 2020 진준호. All rights reserved.

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using pii = std::pair<int, int>;
constexpr int INF = 3 * 800 * 1000 + 1;

std::vector<int> dijkstra(int start, const std::vector<std::vector<pii>> &adj)
{
    std::vector<int> dist(adj.size(), INF);
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty())
    {
        const auto [cost, node] = pq.top();
        pq.pop();
        if(dist[node] < cost)
        {
            continue;
        }
        for(const auto &[next, weight] : adj[node])
        {
            const int nextDist = cost + weight;
            if(nextDist < dist[next])
            {
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
    return dist;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, e, v1, v2;
    std::cin >> n >> e;
    std::vector<std::vector<pii>> adj(n + 1);
    for(int i = 0; i < e; i++)
    {
        int from, to, weight;
        std::cin >> from >> to >> weight;
        adj[from].push_back({to, weight});
        adj[to].push_back({from, weight});
    }
    std::cin >> v1 >> v2;

    const auto dist1 = dijkstra(1, adj);
    const auto distV1 = dijkstra(v1, adj);
    const auto distV2 = dijkstra(v2, adj);
    const int answer = std::min(dist1[v1] + distV1[v2] + distV2[n],
                                dist1[v2] + distV2[v1] + distV1[n]);
    std::cout << (answer >= INF ? -1 : answer) << '\n';
    return 0;
}
