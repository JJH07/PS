//  Copyright © 2020 진준호. All rights reserved.

#include <iostream>

int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, limit = 10, total = 0, digits = 1;

    std::cin >> n;

    while(limit <= n)
    {
        total += digits * (limit - (limit / 10));

        limit *= 10;
        digits++;
    }
    total += digits * (n - (limit / 10) + 1);

    std::cout << total << '\n';

    return 0;
}
