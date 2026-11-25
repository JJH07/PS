// Copyright © 2020 진준호. All rights reserved.

#include <iostream>
#include <cmath>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int diagonal, h, w;

    std::cin >> diagonal >> h >> w;

    const double ratioDiagonal = std::sqrt(h * h + w * w);
    std::cout << static_cast<int>(diagonal * h / ratioDiagonal) << ' '
              << static_cast<int>(diagonal * w / ratioDiagonal) << '\n';
    return 0;
}
