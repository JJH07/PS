#include <iostream>
typedef long long ll;
const ll MOD = 1e9 + 7;
ll factorial[1001];

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    factorial[0] = 1;
    for(ll i = 1; i <= 1000; i++)
    {
        factorial[i] = (i * factorial[i - 1]) % MOD;
    }

    int n, x, pos;
    std::cin >> n >> x >> pos;

    int l = 0, r = n;
    ll ans = 1, s = x - 1, g = n - x, rest = n;

    while(l < r)
    {
        int mid = (l + r) / 2;
        if(mid == pos)
        {
            l = mid + 1;
        }
        else if(mid < pos)
        {
            ans = (ans * s) % MOD;
            --s;
            l = mid + 1;
        }
        else
        {
            ans = (ans * g) % MOD;
            --g;
            r = mid;
        }
        --rest;
    }
    ans = (ans * factorial[rest]) % MOD;
    std::cout << ans << '\n';
    return 0;
}