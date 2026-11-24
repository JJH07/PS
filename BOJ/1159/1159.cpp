// Copyright © 2020 진준호. All rights reserved.

#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, counts[26]{};
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::string name;
        std::cin >> name;
        counts[name[0] - 'a']++;
    }
    std::string initials;
    for(int i = 0; i < 26; i++)
    {
        if(counts[i] >= 5)
        {
            initials += static_cast<char>('a' + i);
        }
    }
    std::cout << (initials.empty() ? "PREDAJA" : initials) << '\n';
    return 0;
}
