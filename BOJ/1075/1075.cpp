// Copyright © 2019 진준호. All rights reserved.

#include <iomanip>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int number, divisor;
    std::cin >> number >> divisor;

    const int base = number / 100 * 100;
    const int suffix = (divisor - base % divisor) % divisor;
    std::cout << std::setfill('0') << std::setw(2) << suffix << '\n';
    return 0;
}
