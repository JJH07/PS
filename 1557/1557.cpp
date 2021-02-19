#include <iostream>
#define MAX 50000
#define INF 2000000000
typedef long long ll;
ll t[MAX];
void init()
{
    t[1] = 1;
    for(int i = 1; i < MAX; i++)
    {
        for(int j = 2 * i; j < MAX; j += i)
        {
            t[j] -= t[i];
        }
    }
}
ll func(ll n)
{
    ll ret = 0;
    for(ll i = 1; i * i <= n; i++)
    {
        ret += t[i] * (n / (i * i));
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    init();
    ll k;
    std::cin >> k;
    ll l = 1, r = INF;
    while(l <= r)
    {
        ll mid = (l + r) >> 1;
        if(func(mid) < k)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    std::cout << l << '\n';
    return 0;
}