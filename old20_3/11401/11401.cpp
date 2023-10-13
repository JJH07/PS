#include <iostream>
#include <vector>

#define MOD 1000000007
typedef long long ll;

ll pow(ll x, ll y)
{
    if(y == 0)
    {
        return 1;
    }
    if(y % 2)
    {
        return (pow(x, y - 1) * x) % MOD;
    }
    else
    {
        ll t = pow(x, y / 2) % MOD;
        return (t * t) % MOD;
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, k;
    std::cin >> n >> k;
    ll top = 1, down = 1;
    for(ll i = 1; i <= n; i++)
    {
        top *= i;
        top %= MOD;
    }
    for(ll i = 1; i <= k; i++)
    {
        down *= i;
        down %= MOD;
    }
    for(ll i = 1; i <= n - k; i++)
    {
        down *= i;
        down %= MOD;
    }
    down = pow(down, MOD - 2) % MOD;
    ll ans = (top * down) % MOD;
    std::cout << ans << '\n';
    return 0;
}