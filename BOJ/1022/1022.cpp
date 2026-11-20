// Copyright © 2020 진준호. All rights reserved.

#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

long long spiralValueAt(int row, int column)
{
    const int radius = std::max(std::abs(row), std::abs(column));
    const long long sideLength = 2LL * radius + 1;
    const long long cornerValue = sideLength * sideLength;

    // Each ring ends at its bottom-right corner: (radius, radius).
    if(row == radius)
    {
        return cornerValue - (radius - column);
    }
    if(column == -radius)
    {
        return cornerValue - 2LL * radius - (radius - row);
    }
    if(row == -radius)
    {
        return cornerValue - 4LL * radius - (column + radius);
    }
    return cornerValue - 6LL * radius - (row + radius);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int firstRow, firstColumn, lastRow, lastColumn;
    std::cin >> firstRow >> firstColumn >> lastRow >> lastColumn;

    long long maximumValue = 0;
    for(int row = firstRow; row <= lastRow; row++)
    {
        for(int column = firstColumn; column <= lastColumn; column++)
        {
            maximumValue = std::max(maximumValue, spiralValueAt(row, column));
        }
    }
    const int outputWidth = static_cast<int>(std::to_string(maximumValue).size());
    for(int row = firstRow; row <= lastRow; row++)
    {
        for(int column = firstColumn; column <= lastColumn; column++)
        {
            if(column > firstColumn)
            {
                std::cout << ' ';
            }
            std::cout << std::setw(outputWidth) << spiralValueAt(row, column);
        }
        std::cout << '\n';
    }
    return 0;
}
