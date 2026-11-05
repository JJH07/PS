#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
#define MAX 201
#define INF 1e9
typedef std::pair<int, int> pii;
int n, m, distance[MAX];
std::vector<pii> link[MAX];
double ignite(int node)
{
    std::priority_queue<pii> pq;
    std::fill(distance, distance + MAX, (int)INF);
    pq.push({0, node});
    distance[node] = 0;
    while(!pq.empty())
    {
        auto [dist, now] = pq.top();
        pq.pop();
        dist *= -1;
        if(distance[now] < dist)
        {
            continue;
        }
        for(auto [next, v] : link[now])
        {
            int nDist = dist + v;
            if(distance[next] > nDist)
            {
                pq.push({-nDist, next});
                distance[next] = nDist;
            }
        }
    }
    double ret = 0.0;
    for(int s = 1; s <= n; s++)
    {
        for(auto [e, v] : link[s])
        {
            int S = distance[s];
            int E = distance[e];
            if(S > E)
            {
                std::swap(S, E);
            }
            if(E - S >= v)
            {
                ret = std::max(ret, (double)(S + v));
            }
            else
            {
                ret = std::max(ret, E + (v - (E - S)) / 2.0);      
            }
        }
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::fixed;
    std::cout.precision(1);
    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int s, e, l;
        std::cin >> s >> e >> l;
        link[s].push_back({e, l});
        link[e].push_back({s, l});
    }
    double ans = INF;
    for(int i = 1; i <= n; i++)
    {
        ans = std::min(ans, ignite(i));
    }
    std::cout << ans << '\n';
    return 0;
}