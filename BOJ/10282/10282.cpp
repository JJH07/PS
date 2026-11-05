#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
const int INF = 1e9;
struct pqn{
    int idx;
    int dist;
    bool operator<(const pqn &rhs)const{
        return dist > rhs.dist;
    }
};
int distance[10001];
std::vector<pqn> dependency[10001];
std::priority_queue<pqn> pq;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int n, d, c, cnt = 0, time = 0;
        std::cin >> n >> d >> c;

        std::fill(distance, distance + n + 1, INF);
        for(int i = 1; i <= n; i++)
        {
            dependency[i].clear();
        }

        for(int i = 0; i < d; i++)
        {
            int a, b, s;
            std::cin >> a >> b >> s;
            dependency[b].push_back({a, s});
        }

        distance[c] = 0;
        pq.push({c, 0});
        while(!pq.empty())
        {
            auto [now, d] = pq.top();
            pq.pop();
            if(distance[now] < d)
            {
                continue;
            }
            
            cnt++;
            time = std::max(time, d);
            for(auto [next, val] : dependency[now])
            {
                int nval = distance[now] + val;
                if(nval < distance[next])
                {
                    distance[next] = nval;
                    pq.push({next, nval});
                }
            }
        }
        std::cout << cnt << ' ' << time << '\n';
    }

    return 0;
}