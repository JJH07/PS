#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;

ll n;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    ll ans = n;
    for(ll i = 2; i <= sqrt(n); i++)
    {
        if(n % i)
        {
            continue;
        }
        while(n % i == 0)
        {
            n /= i;
        }
        ans = ans / i * (i - 1);
    }
    if(n > 1)
    {
        ans = ans / n * (n - 1);
    }
    std::cout << ans << '\n';
    return 0;
}