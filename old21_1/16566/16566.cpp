#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 4000001
int n, m, k, used[MAX];
std::vector<int> list;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int number;
        std::cin >> number;
        list.push_back(number);
    }
    std::sort(list.begin(), list.end());
    for(int i = 0; i < k; i++)
    {
        int red;
        std::cin >> red;
        auto it = std::lower_bound(list.begin(), list.end(), red + 1);
        while(used[*it])
        {
            it++;
        }
        used[*it] = 1;
        std::cout << *it << '\n';
    }
    return 0;
}