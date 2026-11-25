#include <iostream>
constexpr int MAX = 50000;
constexpr long long LIMIT = 2000000000;
typedef long long ll;
ll mu[MAX];
void buildMobius()
{
    mu[1] = 1;
    for(int i = 1; i < MAX; i++)
    {
        if(mu[i] == 0)
        {
            continue;
        }
        for(int j = 2 * i; j < MAX; j += i)
        {
            mu[j] -= mu[i];
        }
    }
}
ll countSquareFree(ll n)
{
    ll count = 0;
    for(ll i = 1; i * i <= n; i++)
    {
        if(mu[i] != 0)
        {
            count += mu[i] * (n / (i * i));
        }
    }
    return count;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    buildMobius();
    ll k;
    std::cin >> k;
    ll left = 1, right = LIMIT;
    while(left <= right)
    {
        ll mid = (left + right) >> 1;
        if(countSquareFree(mid) < k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    std::cout << left << '\n';
    return 0;
}
