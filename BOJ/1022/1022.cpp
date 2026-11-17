//
//  main.cpp
//  1022
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
int spiralValues[51][6], digitCounts[51][6], firstRow, firstColumn, lastRow, lastColumn, currentRow, currentColumn, outputWidth;
int rowOffsets[4] = {0, -1, 0, 1}, columnOffsets[4] = {1, 0, -1, 0};
bool isInsideOutputArea()
{
    if(currentRow >= 0 && currentRow <= lastRow && currentColumn >= 0 && currentColumn <= lastColumn)
    {
        return true;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...

    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int storedCellCountPlusOne = 1, currentValue = 1, legLength = 0, directionIndex = 0;
    
    std::cin >> firstRow >> firstColumn >> lastRow >> lastColumn;
    
    lastRow -= firstRow;
    lastColumn -= firstColumn;
    currentRow -= firstRow;
    currentColumn -= firstColumn;
    firstRow = 0;
    firstColumn = 0;

    if(isInsideOutputArea())
    {
        spiralValues[currentRow][currentColumn] = currentValue;
        storedCellCountPlusOne++;
        outputWidth = 1;
        digitCounts[currentRow][currentColumn] = 1;
    }
    currentValue++;
    while(storedCellCountPlusOne <= (lastRow + 1) * (lastColumn + 1))
    {
        if(directionIndex % 2 == 0)
        {
            legLength++;
        }
        for(int i = 1; i <= legLength; i++)
        {
            currentRow += rowOffsets[directionIndex];
            currentColumn += columnOffsets[directionIndex];
            if(isInsideOutputArea())
            {
                spiralValues[currentRow][currentColumn] = currentValue;
                storedCellCountPlusOne++;
                
                int remainingDigits = currentValue, digitCount = 0;
                while(remainingDigits > 0)
                {
                    digitCount++;
                    remainingDigits /= 10;
                }
                digitCounts[currentRow][currentColumn] = digitCount;
                outputWidth = digitCount;
            }
            currentValue++;
        }
        directionIndex = (directionIndex + 1) % 4;
    }
    for(int i = 0; i <= lastRow; i++)
    {
        for(int j = 0; j <= lastColumn; j++)
        {
            for(int k = 0; k < outputWidth - digitCounts[i][j]; k++)
            {
                std::cout << ' ';
            }
            std::cout << spiralValues[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
