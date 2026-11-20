// Copyright © 2019 진준호. All rights reserved.

#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long rangeStart, rangeEnd;
    std::cin >> rangeStart >> rangeEnd;

    const long long rangeLength = rangeEnd - rangeStart + 1;
    std::vector<bool> hasSquareFactor(rangeLength, false);

    for(long long divisor = 2; divisor * divisor <= rangeEnd; divisor++)
    {
        const long long square = divisor * divisor;
        const long long firstMultiple = ((rangeStart + square - 1) / square) * square;
        for(long long multiple = firstMultiple; multiple <= rangeEnd; multiple += square)
        {
            hasSquareFactor[multiple - rangeStart] = true;
        }
    }

    long long squareFreeCount = 0;
    for(bool excluded : hasSquareFactor)
    {
        if(!excluded)
        {
            squareFreeCount++;
        }
    }
    std::cout << squareFreeCount << '\n';
    return 0;
}
