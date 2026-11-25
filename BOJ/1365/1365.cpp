#include <algorithm>
#include <iostream>
#include <vector>
int n;
std::vector<int> tails;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    tails.push_back(0);
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int value;
        std::cin >> value;
        if(tails.back() < value)
        {
            tails.push_back(value);
        }
        else
        {
            const auto it = std::lower_bound(tails.begin(), tails.end(), value);
            *it = value;
        }
    }
    std::cout << n - (tails.size() - 1) << '\n';
    return 0;
}
