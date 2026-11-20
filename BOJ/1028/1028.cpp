// Copyright © 2020 진준호. All rights reserved.

#include <algorithm>
#include <iostream>
#include <string>

int downLeft[750][750], downRight[750][750];
std::string mine[750];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int rowCount, columnCount;
    std::cin >> rowCount >> columnCount;
    for(int row = 0; row < rowCount; row++)
    {
        std::cin >> mine[row];
    }

    // Only read a neighboring cell after checking its coordinates.
    for(int row = rowCount - 1; row >= 0; row--)
    {
        for(int column = 0; column < columnCount; column++)
        {
            if(mine[row][column] == '0')
            {
                continue;
            }
            downLeft[row][column] = 1;
            downRight[row][column] = 1;
            if(row + 1 < rowCount && column > 0)
            {
                downLeft[row][column] += downLeft[row + 1][column - 1];
            }
            if(row + 1 < rowCount && column + 1 < columnCount)
            {
                downRight[row][column] += downRight[row + 1][column + 1];
            }
        }
    }

    int largestDiamond = 0;
    for(int row = 0; row < rowCount; row++)
    {
        for(int column = 0; column < columnCount; column++)
        {
            int candidateSize = std::min(downLeft[row][column], downRight[row][column]);
            candidateSize = std::min(candidateSize, (rowCount - row + 1) / 2);
            for(; candidateSize > largestDiamond; candidateSize--)
            {
                const int middleRow = row + candidateSize - 1;
                const int leftColumn = column - candidateSize + 1;
                const int rightColumn = column + candidateSize - 1;
                if(downRight[middleRow][leftColumn] >= candidateSize &&
                   downLeft[middleRow][rightColumn] >= candidateSize)
                {
                    largestDiamond = candidateSize;
                    break;
                }
            }
        }
    }
    std::cout << largestDiamond << '\n';
    return 0;
}
