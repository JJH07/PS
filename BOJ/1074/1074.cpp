// Copyright © 2019 진준호. All rights reserved.

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int exponent, targetRow, targetColumn;
    std::cin >> exponent >> targetRow >> targetColumn;
    int sideLength = 1 << exponent;
    long long visitIndex = 0;
    while(sideLength > 1)
    {
        const int halfLength = sideLength / 2;
        int quadrant = 0;
        if(targetRow >= halfLength)
        {
            quadrant += 2;
            targetRow -= halfLength;
        }
        if(targetColumn >= halfLength)
        {
            quadrant++;
            targetColumn -= halfLength;
        }
        visitIndex += quadrant * 1LL * halfLength * halfLength;
        sideLength = halfLength;
    }
    std::cout << visitIndex << '\n';
    return 0;
}
