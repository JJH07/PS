#include <iostream>
#include <cstring>
typedef long long ll;
#define MAX 1000001
const ll MOD = 1e9 + 7;
int n;
ll dp[MAX], dp2[MAX];
ll reverse(int n)
{
    ll &ret = dp[n];
    if(ret != -1)
    {
        return ret;
    }
    ret = (reverse(n - 1) * 2 + 2) % MOD;
    return ret;
}
ll move(int n)
{
    ll &ret = dp2[n];
    if(ret != -1)
    {
        return ret;
    }
    ret = (reverse(n) + move(n - 1) + 2) % MOD;
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));
    std::memset(dp2, -1, sizeof(dp2));
    dp[1] = 2;
    dp2[1] = 3;
    std::cin >> n;
    ll ans = move(n);
    std::cout << ans << '\n';
    return 0;
}