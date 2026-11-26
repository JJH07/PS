#include <iostream>
#include <utility>
#include <vector>

using ll = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tests;
    std::cin >> tests;
    while(tests--)
    {
        int n, roads, holes;
        std::cin >> n >> roads >> holes;
        std::vector<std::vector<std::pair<int, ll>>> adj(n + 1);
        for(int i = 0; i < roads; i++)
        {
            int from, to;
            ll time;
            std::cin >> from >> to >> time;
            adj[from].push_back({to, time});
            adj[to].push_back({from, time});
        }
        for(int i = 0; i < holes; i++)
        {
            int from, to;
            ll time;
            std::cin >> from >> to >> time;
            adj[from].push_back({to, -time});
        }

        std::vector<ll> dist(n + 1, 0);
        bool hasCycle = false;
        for(int pass = 1; pass <= n; pass++)
        {
            bool changed = false;
            for(int node = 1; node <= n; node++)
            {
                for(auto [next, weight] : adj[node])
                {
                    if(dist[next] > dist[node] + weight)
                    {
                        dist[next] = dist[node] + weight;
                        changed = true;
                    }
                }
            }
            if(!changed)
            {
                break;
            }
            if(pass == n)
            {
                hasCycle = true;
            }
        }
        std::cout << (hasCycle ? "YES\n" : "NO\n");
    }
    return 0;
}
