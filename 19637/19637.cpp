#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> ATK;
    std::vector<std::string> name;
    for(int i = 0; i < n; i++)
    {
        std::string n;
        int idx;
        std::cin >> n >> idx;
        ATK.push_back(idx);
        name.push_back(n);
    }
    for(int i = 0; i < m; i++)
    {
        int X;
        std::cin >> X;
        auto lit = std::lower_bound(ATK.begin(), ATK.end(), X);
        std::cout << name[lit - ATK.begin()] << '\n';
    }
    return 0;
}