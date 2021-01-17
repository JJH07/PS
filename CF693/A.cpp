#include <iostream>
typedef long long ll;
ll cut(int n)
{
    ll ret = 1;
    while(!(n % 2))
    {
        n /= 2;
        ret *= 2;
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int w, h, n;
        std::cin >> w >> h >> n;
        ll ans = cut(w) * cut(h);
        std::cout << (ans >= n ? "YES\n" : "NO\n");
    }
    return 0;
}