//  Copyright © 2020 진준호. All rights reserved.

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::set<std::string> names;
    std::string name;
    std::vector<std::string> common;

    std::cin >> n >> m;
    common.reserve(std::min(n, m));

    for(int i = 0; i < n; i++)
    {
        std::cin >> name;
        names.insert(name);
    }
    for(int i = 0; i < m; i++)
    {
        std::cin >> name;
        if(names.find(name) != names.end())
        {
            common.push_back(name);
        }
    }
    std::sort(common.begin(), common.end());

    std::cout << (int)common.size() << '\n';
    for(const auto &name : common)
    {
        std::cout << name << '\n';
    }

    return 0;
}
