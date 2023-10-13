#include <iostream>

typedef long long ll;
const int MOD = 1e9 + 7;
ll n, x, N[1000002], ans;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> x;
    for(int i = 0; i <= n; i++)
    {
        ll A, t;
        std::cin >> A >> t;
        N[t] = A;
    }
    for(int i = n + 1; i > 0; i--)
    {
        ans = x * ans + N[i - 1];
        ans %= MOD;
    }
    std::cout << ans << '\n';
    return 0;
}