#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

const int MAX_V = 1e9;
struct link_n{
    int node, cost, time;
    link_n(int N, int C, int T) : node(N), cost(C), time(T){}
    bool operator<(const link_n &rhs) const{
        return time > rhs.time;
    }
};
int n, m, k;
int dist[101][10001];
std::vector<link_n> route[101];
std::priority_queue<link_n> pq;
int Dijkstra()
{
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            dist[i][j] = MAX_V;
        }
    }
    dist[1][0] = 0;
    pq.push(link_n(1, 0, 0));
    while(!pq.empty())
    {
        auto [now, cost, time] = pq.top();
        pq.pop();

        for(auto &flight : route[now])
        {
            int next = flight.node;
            int ncost = cost + flight.cost;
            int ntime = dist[now][cost] + flight.time;
            if(ncost > m || ntime >= dist[next][ncost])
            {
                continue;
            }
            dist[next][ncost] = ntime;
            pq.push(link_n(next, ncost, ntime));
        }
    }
    int ret = MAX_V;
    for(int i = 0; i <= m; i++)
    {
        if(dist[n][i] != MAX_V)
        {
            ret = std::min(ret, dist[n][i]);
        }
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while(T--)
    {
        std::cin >> n >> m >> k;
        for(int i = 0; i < k; i++)
        {
            int u, v, c, d;
            std::cin >> u >> v >> c >> d;
            route[u].push_back(link_n(v, c, d));
        }    
        int ans = Dijkstra();
        if(ans == MAX_V)
        {
            std::cout << "Poor KCM\n";
        }
        else
        {
            std::cout << ans << '\n';
        }
        for(int i = 1; i <= n; i++)
        {
            route[i].clear();
        }
    }
    
    
    return 0;
}