#include <iostream>

typedef long long ll;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n, k, q;
    std::cin >> n >> k >> q;
    while(q--)
    {
        ll x, y;
        ll ans = 0;
        std::cin >> x >> y;
        if(x > y)
        {
            std::swap(x, y);
        }
        if(k == 1)
        {
            std::cout << y - x << '\n';
        }
        else
        {
            while(x < y)
            {
                y = (y + k - 2) / k;
                if(x > y)
                {
                    std::swap(x, y);
                }
                ans++;
            }
            std::cout << ans << '\n';
        }
    }
    return 0;
}