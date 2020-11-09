#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cstring>
#define MAX 1005
#define INF 1e12
typedef long long ll;
typedef std::pair<ll, ll> pii;

int n, m, k;
std::vector<pii> road[MAX];
ll distance[MAX][MAX];

void dijkstra(int start)
{
    std::priority_queue<pii> pq;
    
    pq.push({0, start});
    distance[start][start] = 0;

    while(!pq.empty())
    {
        auto [dist, now] = pq.top();
        pq.pop();
        if(distance[start][now] < -dist)
        {
            continue;
        }
        for(pii &next : road[now])
        {
            ll ndist = distance[start][now] + next.second;
            if(distance[start][next.first] > ndist)
            {
                distance[start][next.first] = ndist;
                pq.push({-ndist, next.first});
            }
        }
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            distance[i][j] = INF;
        }
    }

    std::cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        ll x, y, w;
        std::cin >> x >> y >> w;
        road[x].push_back({y, w});
        road[y].push_back({x, w});
    }
    std::vector<pii> routes;
    for(int i = 0; i < k; i++)
    {
        int from, to;
        std::cin >> from >> to;
        routes.push_back({from, to});
    }
    for(int i = 1; i <= n; i++)
    {
        dijkstra(i);
    }
    ll ans = INF;
    for(int x = 1; x <= n; x++)
    {
        for(auto [y, w] : road[x])
        {
            ll V = 0;
            for(auto [start, end] : routes)
            {
                V += std::min({distance[start][end], distance[start][x] + distance[y][end], distance[start][y] + distance[x][end]});
            }
            ans = std::min(ans, V);
        }
    }
    std::cout << ans << '\n';
    return 0;
}