#include <iostream>
#include <algorithm>

typedef long long ll;
const ll INF = 1e9;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int V, E;
    ll route[401][401];
    std::fill(route[0], route[0] + 401 * 401, INF);
    std::cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        int a, b;
        ll c;
        std::cin >> a >> b >> c;
        route[a][b] = c;
    }
    for(int k = 1; k <= V; k++)
    {
        for(int i = 1; i <= V; i++)
        {
            if(i == k || route[i][k] == INF)
            {
                continue;
            }
            for(int j = 1; j <= V; j++)
            {
                if(route[k][j] == INF)
                {
                    continue;
                }
                route[i][j] = std::min(route[i][j], route[i][k] + route[k][j]);
            }
        }
    }
    ll ans = INF;
    for(int i = 1; i <= V; i++)
    {
        ans = std::min(ans, route[i][i]);
    }
    std::cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}