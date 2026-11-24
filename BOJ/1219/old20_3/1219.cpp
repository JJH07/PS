#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

constexpr long long UNREACHABLE = -1000000000;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, start, end, m;
    long long income[100], dist[100];
    std::vector<std::pair<int, long long>> adj[100];
    std::queue<int> q;
    std::fill(dist, dist + 100, UNREACHABLE);

    std::cin >> n >> start >> end >> m;
    for(int i = 0; i < m; i++)
    {
        int from, to;
        long long cost;
        std::cin >> from >> to >> cost;
        adj[from].push_back({to, cost});
    }
    for(int i = 0; i < n; i++)
    {
        std::cin >> income[i];
    }
    dist[start] = income[start];
    for(int pass = 1; pass <= n; pass++)
    {
        bool updated = false;
        for(int from = 0; from < n; from++)
        {
            if(dist[from] == UNREACHABLE)
            {
                continue;
            }
            for(const auto &[to, cost] : adj[from])
            {
                const long long profit = dist[from] + income[to] - cost;
                if(dist[to] < profit)
                {
                    dist[to] = profit;
                    updated = true;
                    if(pass == n)
                    {
                        q.push(from);
                    }
                }
            }
        }
        if(!updated)
        {
            break;
        }
    }

    bool visited[100]{};
    bool unbounded = false;
    while(!q.empty())
    {
        const int node = q.front();
        q.pop();
        if(node == end)
        {
            unbounded = true;
            break;
        }
        for(const auto &edge : adj[node])
        {
            const int next = edge.first;
            if(!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    if(dist[end] == UNREACHABLE)
    {
        std::cout << "gg\n";
    }
    else if(unbounded)
    {
        std::cout << "Gee\n";
    }
    else
    {
        std::cout << dist[end] << '\n';
    }
    return 0;
}
