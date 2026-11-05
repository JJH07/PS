#include <iostream>
#include <vector>
typedef long long ll;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    ll ans;
    std::cin >> t;
    while(t--)
    {
        ll a, b, x, y, n, ans;
        std::cin >> a >> b >> x >> y >> n;
        ll alen = std::max(x, a - n);
        ll blen = std::max(y, b - n);
        if(alen <= blen)
        {
            n -= a - alen;
            a = alen;
            b -= n;
            b = std::max(b, y);
        }
        else
        {
            n -= b - blen;
            b = blen;
            a -= n;
            a = std::max(a, x);
        }
        ans = a * b;
        std::cout << ans << '\n';        
    }
    return 0;
}