#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 200001
typedef long long ll;
int n, m;
ll Y[MAX];
std::vector<std::pair<int, ll>> list;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        ll x, y;
        std::cin >> x >> y;
        Y[i] = y;
    }
    for(int i = 0; i < m; i++)
    {
        int u, v;
        ll c;
        std::cin >> u >> v >> c;
        ll s = std::min(Y[u], Y[v]);
        ll e = std::max(Y[u], Y[v]);
        list.push_back({s, c});
        list.push_back({e + 1, -c});
    }
    std::sort(list.begin(), list.end());
    ll temp = 0, ans = 0;
    for(int i = 0; i < (int)list.size(); i++)
    {
        temp += list[i].second;
        for(; i < (int)list.size() - 1; i++)
        {
            if(list[i].first != list[i + 1].first)
            {
                break;
            }
            temp += list[i + 1].second;
        }
        ans = std::max(ans, temp);
    }
    std::cout << ans << '\n';
    return 0;
}