#include <iostream>
#define MAX 1000100
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
    ll Min, Max;
    std::cin >> Min >> Max;
    std::cout << func(Max) - func(Min - 1) << '\n';
    return 0;
}