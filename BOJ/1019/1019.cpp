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
    
    int n, tmp, max_step = 1, count[10];
    
    std::fill(count, count + 10, 0);
    
    std::cin >> n;
    
    tmp = n;
    while(tmp > 0)
    {
        max_step *= 10;
        tmp /= 10;
    }
    
    for(int step = 1; step < max_step; step *= 10)
    {
        int left = n / step / 10;
        int mid = n / step % 10;
        int right = n % step;
        
        if(left == 0)
        {
            for(int i = 1; i < mid; i++)
            {
                count[i] += step;
            }
            count[mid] += right + 1;
        }
        else
        {
            for(int i = 1; i <= 9; i++)
            {
                count[i] += step;
            }
            for(int i = 0; i <= 9; i++)
            {
                count[i] += (left - 1) * step;
            }
            for(int i = 0; i < mid; i++)
            {
                count[i] += step;
            }
            count[mid] += right + 1;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        std::cout << count[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}
