#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
typedef long long ll;
std::vector<int> list;
ll dp[200001][2];
ll Comb(int n, int r)
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
    else if(r == 1)
    {
        return ret = n;
    }
    return ret = Comb(n - 1, r - 1) + Comb(n - 1, r);
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
        int n;
        std::cin >> n;
        list.resize(n);
        for(int i = 0; i < n; i++)
        {
            std::cin >> list[i];
        }
        std::sort(list.begin(), list.end());

        ll ans = 0;
        for(auto s = list.begin(); s != list.end(); s++)
        {
            auto e = std::upper_bound(list.begin(), list.end(), *s + 2);
            if(e - s < 3)
            {
                continue;
            }
            ans += Comb(e - s - 1, 2);
        }
        std::cout << ans << '\n';
    }
    return 0;
}