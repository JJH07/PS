#include <iostream>
#include <queue>
#include <set>
#include <utility>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::priority_queue<std::pair<int, int>> jewels;
    std::multiset<int> bags;
    std::cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int mass, value;
        std::cin >> mass >> value;
        jewels.push({value, mass});
    }
    for(int i = 0; i < k; i++)
    {
        int capacity;
        std::cin >> capacity;
        bags.insert(capacity);
    }

    long long totalValue = 0;
    while(!jewels.empty() && !bags.empty())
    {
        const auto [value, mass] = jewels.top();
        jewels.pop();
        const auto it = bags.lower_bound(mass);
        if(it == bags.end())
        {
            continue;
        }
        totalValue += value;
        bags.erase(it);
    }
    std::cout << totalValue << '\n';
    return 0;
}
