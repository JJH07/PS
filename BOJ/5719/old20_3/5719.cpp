#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

const int INF = 1e6;
struct pqn
{
    int idx, d;
    bool operator<(const pqn &rhs)const{
        return d > rhs.d;
    }
};

int N, M, S, D, dist[500];
bool BLOCKED[500][500];
std::vector<std::pair<int, int>> route[500];
std::vector<int> parent[500];
std::priority_queue<pqn> pq;

int dijkstra()
{
    std::fill(dist, dist + 500, INF);
    dist[S] = 0;
    pq.push({S, 0});
    while(!pq.empty())
    {
        auto [idx, d] = pq.top();
        pq.pop();
        if(dist[idx] < d)
        {
            continue;
        }
        for(auto [next, w] : route[idx])
        {
            if(BLOCKED[idx][next])
            {
                continue;
            }
            int nd = dist[idx] + w;
            if(dist[next] > nd)
            {
                dist[next] = nd;
                parent[next].clear();
                parent[next].push_back(idx);
                pq.push({next, nd});
            }
            else if(dist[next] == nd)
            {
                parent[next].push_back(idx);
            }
        }
    }
    return dist[D];
}
void check()
{
    std::queue<int> q;
    q.push(D);
    while(!q.empty())
    {
        int idx = q.front();
        q.pop();
        for(auto p : parent[idx])
        {
            if(BLOCKED[p][idx])
            {
                continue;
            }
            BLOCKED[p][idx] = 1;
            q.push(p);
        }
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    while(1)
    {
        std::cin >> N >> M;
        if(N == 0 && M == 0)
        {
            break;
        }

        for(int i = 0; i < 500; i++)
        {
            route[i].clear();
            parent[i].clear();
        }
        std::memset(BLOCKED, 0, sizeof(BLOCKED));

        std::cin >> S >> D;
        for(int i = 0; i < M; i++)
        {
            int u, v, p;
            std::cin >> u >> v >> p;
            route[u].push_back({v, p});
        }
        dijkstra();
        check();
        int ans = dijkstra();
        
        std::cout << (ans == INF ? -1 : ans) << '\n';
    }
}