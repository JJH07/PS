// Copyright © 2020 진준호. All rights reserved.

#include <algorithm>
#include <array>
#include <iostream>

int enemyCounts[2][10001];
int columnCount, squadCapacity;

int minSquadsFrom(int firstColumn, int needsInnerCoverage, int needsOuterCoverage)
{
    // A state bit is 1 if that cell still needs coverage, 0 if already covered.
    std::array<std::array<int, 2>, 2> nextCosts{};
    for(int column = columnCount; column >= firstColumn; column--)
    {
        std::array<std::array<int, 2>, 2> currentCosts{};
        for(int inner = 0; inner <= 1; inner++)
        {
            for(int outer = 0; outer <= 1; outer++)
            {
                int minimum = inner + outer + nextCosts[1][1];
                if(inner && outer && enemyCounts[0][column] + enemyCounts[1][column] <= squadCapacity)
                {
                    minimum = std::min(minimum, 1 + nextCosts[1][1]);
                }
                const bool canPairInner = inner && column < columnCount &&
                    enemyCounts[0][column] + enemyCounts[0][column + 1] <= squadCapacity;
                const bool canPairOuter = outer && column < columnCount &&
                    enemyCounts[1][column] + enemyCounts[1][column + 1] <= squadCapacity;
                if(canPairInner)
                {
                    minimum = std::min(minimum, inner + outer + nextCosts[0][1]);
                }
                if(canPairOuter)
                {
                    minimum = std::min(minimum, inner + outer + nextCosts[1][0]);
                }
                if(canPairInner && canPairOuter)
                {
                    minimum = std::min(minimum, 2 + nextCosts[0][0]);
                }
                currentCosts[inner][outer] = minimum;
            }
        }
        nextCosts = currentCosts;
    }
    return nextCosts[needsInnerCoverage][needsOuterCoverage];
}

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testCaseCount, minimumSquads, firstColumnEnemies[2], lastColumnEnemies[2];

    std::cin >> testCaseCount;
    while(testCaseCount--)
    {
        std::cin >> columnCount >> squadCapacity;
        for(int i = 0; i < 2; i++)
        {
            for(int j = 1; j <= columnCount; j++)
            {
                std::cin >> enemyCounts[i][j];
            }
        }
        minimumSquads = minSquadsFrom(1, 1, 1);

        // For a wrap pair, skip its first cell and charge one squad at its last cell.
        if(columnCount > 1)
        {
            firstColumnEnemies[0] = enemyCounts[0][1];
            firstColumnEnemies[1] = enemyCounts[1][1];
            lastColumnEnemies[0] = enemyCounts[0][columnCount];
            lastColumnEnemies[1] = enemyCounts[1][columnCount];
            if(firstColumnEnemies[0] + lastColumnEnemies[0] <= squadCapacity)
            {
                enemyCounts[0][1] = squadCapacity;
                enemyCounts[0][columnCount] = squadCapacity;
                minimumSquads = std::min(minimumSquads, minSquadsFrom(1, 0, 1));
            }
            if(firstColumnEnemies[1] + lastColumnEnemies[1] <= squadCapacity)
            {
                enemyCounts[0][1] = firstColumnEnemies[0];
                enemyCounts[0][columnCount] = lastColumnEnemies[0];
                enemyCounts[1][1] = squadCapacity;
                enemyCounts[1][columnCount] = squadCapacity;
                minimumSquads = std::min(minimumSquads, minSquadsFrom(1, 1, 0));
            }
            if(firstColumnEnemies[0] + lastColumnEnemies[0] <= squadCapacity && firstColumnEnemies[1] + lastColumnEnemies[1] <= squadCapacity)
            {
                enemyCounts[0][1] = squadCapacity;
                enemyCounts[0][columnCount] = squadCapacity;
                enemyCounts[1][1] = squadCapacity;
                enemyCounts[1][columnCount] = squadCapacity;
                minimumSquads = std::min(minimumSquads, minSquadsFrom(1, 0, 0));
            }
        }
        std::cout << minimumSquads << '\n';
    }
    return 0;
}
