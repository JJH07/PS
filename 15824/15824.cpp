#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAX 3000000
#define MOD 1000000007
typedef long long ll;
int n;
ll list[MAX], dp[MAX + 1];
ll Pow(int n, int r)
{
    ll &ret = dp[(ll)log2(n) * r];
    if(ret != -1)
    {
        return ret;
    }
    if(r == 0)
    {
        return ret = 1;
    }
    if(r % 2)
    {
        return ret = (Pow(n, r - 1) * n) % MOD;
    }
    ll t = Pow(n, r / 2) % MOD;
    return ret = (t * t) % MOD;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i];
    }
    std::sort(list, list + n);
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ll l = Pow(2, i);
        ll r = Pow(2, n - 1 - i);
        ans = (ans + (l - r) * list[i]) % MOD;
    }
    std::cout << ans << '\n';
    return 0;
}