//
//  main.cpp
//  1024
//
//  Created by 진준호 on 2019/12/31.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int targetSum, minimumLength, firstTerm = -1, lastTerm = -1;
    
    std::cin >> targetSum >> minimumLength;
    
    for(int length = minimumLength; length <= targetSum + 1; length++)
    {
        if(length > 100)
        {
            break;
        }
        if(length % 2 == 1 && targetSum % length == 0)
        {
            firstTerm = (targetSum / length) - length / 2;
            lastTerm = (targetSum / length) + length / 2;
            break;
        }
        else if(length % 2 == 0 && length / 2 == targetSum % length)
        {
            firstTerm = targetSum / length - (length - 1) / 2;
            lastTerm = targetSum / length + length / 2;
            break;
        }
    }
    if(firstTerm < 0)
    {
        std::cout << "-1\n";
    }
    else
    {
        for(int term = firstTerm; term <= lastTerm; term++)
        {
            std::cout << term << ' ';
        }
        std::cout << '\n';
    }
    
    return 0;
}
