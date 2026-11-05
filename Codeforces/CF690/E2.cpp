#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
typedef long long ll;
const ll MOD = 1e9 + 7;
int n, m, k;
std::vector<int> list;
ll dp[200001][101];
ll Combination(int n, int r)
{
    ll &ret = dp[n][r];
    if(ret != -1)
    {
        return ret;
    }
    if(r == 0 || r == n)
    {
        return ret = 1;
    }
    if(r == 1)
    {
        return ret = n;
    }
    return ret = (Combination(n - 1, r - 1) + Combination(n - 1, r)) % MOD;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));
    int t;
    std::cin >> t;
    while(t--)
    {
        ll ans = 0;
        std::cin >> n >> m >> k;
        list.resize(n);
        for(int i = 0; i < n; i++)
        {
            std::cin >> list[i];
        }
        std::sort(list.begin(), list.end());
        for(auto s = list.begin(); s != list.end(); s++)
        {
            auto e = std::upper_bound(s, list.end(), *s + k);
            if(e - s >= m)
            {
                ans = (ans + Combination(e - s - 1, m - 1)) % MOD;
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}