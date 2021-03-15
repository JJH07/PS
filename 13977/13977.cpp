#include <iostream>
#include <cstring>
#define MAX 4000001
#define MOD 1000000007
typedef long long ll;
ll m, Permutation[MAX];
ll Pow(ll x, ll y)
{
    if(y == 0)
    {
        return 1;
    }
    if(y % 2)
    {
        return (Pow(x, y - 1) * x) % MOD;
    }
    ll ret = Pow(x, y / 2) % MOD;
    return (ret * ret) % MOD;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    Permutation[0] = 1;
    for(ll i = 1; i < MAX; i++)
    {
        Permutation[i] = (Permutation[i - 1] * i) % MOD;
    }
    std::cin >> m;
    while(m--)
    {
        ll n, k, A, B;
        std::cin >> n >> k;
        A = Permutation[n];
        B = (Permutation[k] * Permutation[n - k]) % MOD;
        B = Pow(B, MOD - 2) % MOD;
        ll ans = (A * B) % MOD;
        std::cout << ans << '\n';
    }
    return 0;   
}