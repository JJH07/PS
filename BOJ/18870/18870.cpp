#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000
int n, list[MAX];
std::vector<int> check;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i];
        check.push_back(list[i]);
    }
    std::sort(check.begin(), check.end());
    check.erase(std::unique(check.begin(), check.end()), check.end());
    for(int i = 0; i < n; i++)
    {
        auto lit = std::lower_bound(check.begin(), check.end(), list[i]);
        std::cout << lit - check.begin() << ' ';
    }
    return 0;
}