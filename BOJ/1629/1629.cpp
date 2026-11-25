// Copyright © 2019 진준호. All rights reserved.

#include <iostream>
unsigned long long modPow(unsigned long long base, unsigned long long exponent, unsigned long long mod)
{
    if(exponent == 1)
    {
        return base;
    }
    return ((exponent % 2) ? base : 1) * modPow(base * base % mod, exponent / 2, mod) % mod;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned long long a, b, c;

    std::cin >> a >> b >> c;

    std::cout << modPow(a % c, b, c) << '\n';

    return 0;
}
