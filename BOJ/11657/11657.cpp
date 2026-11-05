#include <iostream>
#include <vector>

typedef long long ll;
const int INF = 214700000;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    std::vector<ll> dist(n + 1, INF);
    std::vector<std::pair<int, ll>> route[n + 1];
    
    dist[1] = 0;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        std::cin >> a >> b >> c;
        route[a].push_back(std::make_pair(b, c));
    }
    bool LOOP = false;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(dist[j] == INF)
            {
                continue;
            }
            for(auto [idx, weight] : route[j])
            {
                if(dist[idx] > dist[j] + weight)
                {
                    if(i == n)
                    {
                        LOOP = true;
                    }
                    dist[idx] = dist[j] + weight;
                }
            }
        }
    }
    if(LOOP)
    {
        std::cout << "-1\n";
    }
    else
    {
        for(int i = 2; i <= n; i++)
        {
            std::cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
        }
    }
    return 0;
}