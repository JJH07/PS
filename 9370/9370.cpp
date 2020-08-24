#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

typedef std::pair<int, int> P;
const int MAX_LEN = 214700000;
struct p_n{
    int n, d;
    p_n(int N, int D) : n(N), d(D){}
    bool operator<(const p_n &rhs) const{
        return d > rhs.d;
    }
};
int n, m, t, s, g, h;
int dist1[2001], dist2[2001];
std::vector<std::vector<P>> road;
std::vector<int> Candidate;
void dijkstra(int dist[], int s)
{   
    std::priority_queue<p_n> pq;
    int visited[n + 1];
    std::memset(visited, 0, sizeof(visited));
    dist[s] = 0;
    pq.push(p_n(s, 0));
    while(!pq.empty())
    {
        auto [now, val] = pq.top();
        pq.pop();
        if(visited[now])
        {
            continue;
        }
        visited[now] = 1;
        for(auto next : road[now])
        {
            if(visited[next.first])
            {
                continue;
            }
            int nval = next.second + val;
            if(nval < dist[next.first])
            {
                dist[next.first] = nval;
                pq.push(p_n(next.first, nval));
            }
        }
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int TC;
    std::cin >> TC;
    while(TC--)
    {
        road.clear();
        Candidate.clear();
        std::cin >> n >> m >> t >> s >> g >> h;
        road.resize(n + 1);
        for(int i = 0; i < m; i++)
        {
            int a, b, d;
            std::cin >> a >> b >> d;
            road[a].push_back(std::make_pair(b, d));
            road[b].push_back(std::make_pair(a, d));
        }
        for(int i = 0; i < t; i++)
        {
            int x;
            std::cin >> x;
            Candidate.push_back(x);
        }
        std::sort(Candidate.begin(), Candidate.end());
        std::fill(dist1, dist1 + n + 1, MAX_LEN);
        std::fill(dist2, dist2 + n + 1, MAX_LEN);
        dijkstra(dist1, s);
        int mid = (dist1[g] < dist1[h]) ? h : g;
        dijkstra(dist2, mid);
        for(int C : Candidate)
        {
            if(dist1[mid] + dist2[C] == dist1[C])
            {
                std::cout << C << ' ';
            }
        }
        std::cout << '\n';
    }

    return 0;
}