#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<ll> list(n + 1, 0), rest(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        std::cin >> list[i];
    }
    std::sort(list.begin(), list.end());
    
    return 0;
}