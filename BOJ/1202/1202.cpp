#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
typedef std::pair<int, int> pii;
int n, k;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::priority_queue<pii> jewel;
    std::multiset<int> bag;
    std::cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int mass, value;
        std::cin >> mass >> value;
        jewel.push({value, mass});
    }
    for(int i = 0; i < k; i++)
    {
        int cap;
        std::cin >> cap;
        bag.insert(cap);
    }

    long long ans = 0;
    while(!jewel.empty())
    {
        auto [value, mass] = jewel.top();
        jewel.pop();
        auto lit = bag.lower_bound(mass);
        if(lit == bag.end())
        {
            continue;
        }
        ans += value;
        bag.erase(lit);
    }
    std::cout << ans << '\n';
    return 0;
}