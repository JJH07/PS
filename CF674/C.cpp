#include <iostream>
#include <cmath>
#define MAX 1e9
typedef long long ll;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        ll n;
        std::cin >> n;
        ll ans = MAX;
        for(int i = 1; i <= sqrt(MAX); i++)
        {
            if(i > n)
            {
                break;
            }
            ans = std::min(ans, (i - 1) + ((n - 1) / i));
        }
        std::cout << ans << '\n';
    }
    return 0;
}