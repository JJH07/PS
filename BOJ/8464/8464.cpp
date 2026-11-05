#include <iostream>
#define INF 250000000000
#define MAX 1000000
typedef long long ll;

ll t[MAX];
void init()
{
    t[1] = 1;
    for(ll i = 1; i < MAX; i++)
    {
        for(ll j = i * 2; j < MAX; j += i)
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
        ret += t[i] * n / (i * i);
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    ll n, l = 1, r = INF;
    init();
    std::cin >> n;
    while(l <= r)
    {
        ll mid = (l + r) >> 1;
        if(mid - func(mid) < n)
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