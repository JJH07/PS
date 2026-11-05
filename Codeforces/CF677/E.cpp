#include <iostream>
#include <vector>
typedef long long ll;
int n;
ll table[21][21];
ll Combination(ll n, ll r)
{
    if(n == r || r == 0)
    {
        return 1;
    }
    if(table[n][r] > 0)
    {
        return table[n][r];
    }
    return table[n][r] = Combination(n - 1, r - 1) + Combination(n - 1, r);
}
ll factorial(ll n)
{
    ll ret = 1;
    for(int i = 2; i <= n; i++)
    {
        ret *= i;
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    ll ans = 0;
    std::cin >> n;
    ans = Combination(n - 1, n / 2 - 1) * factorial(n / 2 - 1) * factorial(n / 2 - 1);
    std::cout << ans << '\n';
    return 0;
}