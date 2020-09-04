#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    ll tot = 0, mx = -1;
    std::cin >> n;
    std::vector<ll> list(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        std::cin >> list[i];
        tot += list[i];
        mx = std::max(mx, list[i]);
    }
    if(mx > tot - mx)
    {
        std::cout << mx + mx - tot << '\n';
    }
    else
    {
        std::cout << (tot % 2) << '\n';
    }
    
    return 0;
}