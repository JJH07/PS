//
//  main.cpp
//  1006
//
//  Created by 진준호 on 2020/02/10.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>

int enemyCounts[2][10001], minSquadMemo[10001][2][2];
int columnCount, squadCapacity;
int minSquadsFrom(int column, int needsInnerCoverage, int needsOuterCoverage)
{
    if(column > columnCount)
    {
        return 0;
    }
    int &cachedMinimum = minSquadMemo[column][needsInnerCoverage][needsOuterCoverage];
    if(cachedMinimum != -1)
    {
        return cachedMinimum;
    }
    bool canPairInnerHorizontally = false, canPairOuterHorizontally = false;
    cachedMinimum = needsInnerCoverage + needsOuterCoverage + minSquadsFrom(column + 1, 1, 1);
    if(needsInnerCoverage && needsOuterCoverage && enemyCounts[0][column] + enemyCounts[1][column] <= squadCapacity)
    {
        cachedMinimum = std::min(cachedMinimum, 1 + minSquadsFrom(column + 1, 1, 1));
    }
    if(needsInnerCoverage && column + 1 <= columnCount && enemyCounts[0][column] + enemyCounts[0][column + 1] <= squadCapacity)
    {
        cachedMinimum = std::min(cachedMinimum, needsInnerCoverage + needsOuterCoverage + minSquadsFrom(column + 1, 0, 1));
        canPairInnerHorizontally = true;
    }
    if(needsOuterCoverage && column + 1 <= columnCount && enemyCounts[1][column] + enemyCounts[1][column + 1] <= squadCapacity)
    {
        cachedMinimum = std::min(cachedMinimum, needsInnerCoverage + needsOuterCoverage + minSquadsFrom(column + 1, 1, 0));
        canPairOuterHorizontally = true;
    }
    if(canPairInnerHorizontally && canPairOuterHorizontally)
    {
        cachedMinimum = std::min(cachedMinimum, 2 + minSquadsFrom(column + 1, 0, 0));
    }
    return cachedMinimum;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
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
        std::memset(minSquadMemo, -1, sizeof(minSquadMemo));
        minimumSquads = minSquadsFrom(1, 1, 1);
        
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
                std::memset(minSquadMemo, -1, sizeof(minSquadMemo));
                minimumSquads = std::min(minimumSquads, minSquadsFrom(1, 0, 1));
            }
            if(firstColumnEnemies[1] + lastColumnEnemies[1] <= squadCapacity)
            {
                enemyCounts[0][1] = firstColumnEnemies[0];
                enemyCounts[0][columnCount] = lastColumnEnemies[0];
                enemyCounts[1][1] = squadCapacity;
                enemyCounts[1][columnCount] = squadCapacity;
                std::memset(minSquadMemo, -1, sizeof(minSquadMemo));
                minimumSquads = std::min(minimumSquads, minSquadsFrom(1, 1, 0));
            }
            if(firstColumnEnemies[0] + lastColumnEnemies[0] <= squadCapacity && firstColumnEnemies[1] + lastColumnEnemies[1] <= squadCapacity)
            {
                enemyCounts[0][1] = squadCapacity;
                enemyCounts[0][columnCount] = squadCapacity;
                enemyCounts[1][1] = squadCapacity;
                enemyCounts[1][columnCount] = squadCapacity;
                std::memset(minSquadMemo, -1, sizeof(minSquadMemo));
                minimumSquads = std::min(minimumSquads, minSquadsFrom(1, 0, 0));
            }
        }
        std::cout << minimumSquads << '\n';
    }
    return 0;
}
