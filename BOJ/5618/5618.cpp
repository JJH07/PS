//
//  main.cpp
//  5618
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...

    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, number[3], min_num = 1000000000;
    
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> number[i];
        min_num = std::min(min_num, number[i]);
    }
    for(int i = 1; i <= min_num; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(number[j] % i != 0)
            {
                break;
            }
            if(j == n - 1)
            {
                std::cout << i << '\n';
            }
        }
    }
    
    
    return 0;
}
