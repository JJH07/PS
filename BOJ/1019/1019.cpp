//
//  main.cpp
//  1019
//
//  Created by 진준호 on 2020/01/15.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int lastPage, remainingDigits, placeValueLimit = 1, digitCounts[10];
    
    std::fill(digitCounts, digitCounts + 10, 0);
    
    std::cin >> lastPage;
    
    remainingDigits = lastPage;
    while(remainingDigits > 0)
    {
        placeValueLimit *= 10;
        remainingDigits /= 10;
    }
    
    for(int placeValue = 1; placeValue < placeValueLimit; placeValue *= 10)
    {
        int higherDigits = lastPage / placeValue / 10;
        int currentDigit = lastPage / placeValue % 10;
        int lowerDigits = lastPage % placeValue;
        
        if(higherDigits == 0)
        {
            for(int i = 1; i < currentDigit; i++)
            {
                digitCounts[i] += placeValue;
            }
            digitCounts[currentDigit] += lowerDigits + 1;
        }
        else
        {
            for(int i = 1; i <= 9; i++)
            {
                digitCounts[i] += placeValue;
            }
            for(int i = 0; i <= 9; i++)
            {
                digitCounts[i] += (higherDigits - 1) * placeValue;
            }
            for(int i = 0; i < currentDigit; i++)
            {
                digitCounts[i] += placeValue;
            }
            digitCounts[currentDigit] += lowerDigits + 1;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        std::cout << digitCounts[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}
