#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n;
    std::vector<long long> values(n);
    for(auto &value : values)
    {
        std::cin >> value;
    }
    std::sort(values.begin(), values.end());

    std::cin >> m;
    while(m--)
    {
        long long key;
        std::cin >> key;
        std::cout << std::binary_search(values.begin(), values.end(), key) << '\n';
    }
    return 0;
}
