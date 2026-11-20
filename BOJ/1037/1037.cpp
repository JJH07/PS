// Copyright © 2019 진준호. All rights reserved.

#include <algorithm>
#include <iostream>
#include <limits>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int divisorCount;
    std::cin >> divisorCount;
    int smallestDivisor = std::numeric_limits<int>::max();
    int largestDivisor = 0;
    for(int index = 0; index < divisorCount; index++)
    {
        int divisor;
        std::cin >> divisor;
        smallestDivisor = std::min(smallestDivisor, divisor);
        largestDivisor = std::max(largestDivisor, divisor);
    }
    std::cout << 1LL * smallestDivisor * largestDivisor << '\n';
    return 0;
}
