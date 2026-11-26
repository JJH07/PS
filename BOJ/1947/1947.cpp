// Copyright © 2020 진준호. All rights reserved.

#include <iostream>

using ull = unsigned long long;
constexpr ull MOD = 1000000000;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    ull prev = 1, current = 0;
    for(int i = 2; i <= n; i++)
    {
        ull next = (i - 1) * (current + prev) % MOD;
        prev = current;
        current = next;
    }
    std::cout << current << '\n';
    return 0;
}
