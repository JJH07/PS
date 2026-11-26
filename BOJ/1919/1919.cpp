// Copyright © 2020 진준호. All rights reserved.

#include <cstdlib>
#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string a, b;
    std::cin >> a >> b;
    int counts[26]{};
    for(char ch : a)
    {
        counts[ch - 'a']++;
    }
    for(char ch : b)
    {
        counts[ch - 'a']--;
    }
    int removed = 0;
    for(int count : counts)
    {
        removed += std::abs(count);
    }
    std::cout << removed << '\n';
    return 0;
}
