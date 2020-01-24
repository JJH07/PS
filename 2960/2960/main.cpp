//
//  main.cpp
//  2960
//
//  Created by 진준호 on 2020/01/24.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, k, cnt = 0, number[1001];
    std::fill(number, number + 1001, 1);
    
    std::cin >> n >> k;
    
    for(int i = 2; i <= n; i++)
    {
        if(number[i] == 1)
        {
            for(int j = i; j <= n; j += i)
            {
                if(number[j] == 1)
                {
                    number[j] = 0;
                    cnt++;
                    if(cnt == k)
                    {
                        std::cout << j << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
