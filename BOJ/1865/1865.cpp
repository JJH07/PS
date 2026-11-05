#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 501
#define INF (long long)1e9
typedef long long ll;
typedef std::pair<int, ll> pil;
int n, m, k;
ll distance[MAX];
std::vector<pil> link[MAX]; 
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int tc;
    std::cin >> tc;
    while(tc--)
    {
        std::cin >> n >> m >> k;
        for(int i = 0; i < m; i++)
        {
            int s, e;
            ll t;
            std::cin >> s >> e >> t;
            link[s].push_back({e, t});
            link[e].push_back({s, t});
        }
        for(int i = 0; i < k; i++)
        {
            int s, e;
            ll t;
            std::cin >> s >> e >> t;
            link[s].push_back({e, -t});
        }
        bool FLAG = false; 
        distance[1] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int idx = 1; idx <= n; idx++)
            {
                for(auto [next, v] : link[idx])
                {
                    if(distance[next] > distance[idx] + v)
                    {
                        distance[next] = distance[idx] + v;
                        if(i == n)
                        {
                            FLAG = true;
                        }
                    }
                }
            }
        }
        std::cout << (FLAG ? "YES\n" : "NO\n");

        std::fill(distance, distance + MAX, INF);
        for(int i = 1; i < MAX; i++)
        {
            link[i].clear();
        }
    }
    return 0;
}