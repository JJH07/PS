#include <iostream>
#include <vector>
#include <cstring>

typedef long long ll;
ll n, m, k, dp[301][301];
std::vector<std::pair<int, ll>> link[301];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));

    std::cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
    {
        int a, b;
        ll c;
        std::cin >> a >> b >> c;
        if(a < b)
        {
            link[a].push_back({b, c});
        }
    }
    dp[1][m - 1] = 0;
    for(int now = 1; now < n; now++)
    {
        for(int step = m; step > 0; step--)
        {
            if(dp[now][step] == -1)
            {
                continue;
            }
            for(auto [next, C] : link[now])
            {
                dp[next][step - 1] = std::max(dp[next][step - 1], dp[now][step] + C);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= m; i++)
    {
        ans = std::max(ans, dp[n][i]);
    }
    std::cout << ans << '\n';
    return 0;
}