//
//  main.cpp
//  1016
//
//  Created by 진준호 on 2019/12/30.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <cmath>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    bool hasSquareFactor[1000001];
    long long rangeStart, rangeEnd, squareFreeCount = 0;
    for(int i = 0; i < 1000001; i++)
    {
        hasSquareFactor[i] = false;
    }
    std::cin >> rangeStart >> rangeEnd;
    
    for(long long divisor = 2; divisor * divisor <= rangeEnd; divisor++)
    {
        long long lastMultipleIndex = rangeEnd / (divisor * divisor);
        for(long long multipleIndex = rangeStart / (divisor * divisor); multipleIndex <= lastMultipleIndex; multipleIndex++)
        {
            long long multipleValue = multipleIndex * (divisor * divisor);
            if(multipleValue >= rangeStart && multipleValue <= rangeEnd)
            {
                hasSquareFactor[multipleValue - rangeStart] = true;
            }
        }
    }
    for(int i = 0; i < rangeEnd - rangeStart + 1; i++)
    {
        if(hasSquareFactor[i] == false)
        {
            squareFreeCount++;
        }
    }
    std::cout << squareFreeCount << '\n';
    return 0;
}
