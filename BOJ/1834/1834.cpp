//  Copyright © 2019 진준호. All rights reserved.

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;

    std::cin >> n;

    const long long pairs = n * (n - 1) / 2;
    const long long total = (n + 1) * pairs;
    std::cout << total << '\n';

    return 0;
}
