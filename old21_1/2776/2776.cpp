#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int n, m;
        std::vector<int> list;
        std::cin >> n;
        for(int i = 0; i < n; i++)
        {
            int number;
            std::cin >> number;
            list.push_back(number);
        }
        std::sort(list.begin(), list.end());
        std::cin >> m;
        for(int i = 0; i < m; i++)
        {
            int number;
            std::cin >> number;
            std::cout << std::binary_search(list.begin(), list.end(), number) << '\n';
        }
    }
    return 0;
}