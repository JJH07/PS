//  Copyright © 2019 진준호. All rights reserved.

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long remaining, count = 0;

    std::cin >> remaining;

    while(remaining >= count + 1)
    {
        remaining -= ++count;
    }
    std::cout << count << '\n';
    return 0;
}
