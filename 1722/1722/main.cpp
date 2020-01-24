//
//  main.cpp
//  1722
//
//  Created by 진준호 on 2020/01/07.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    long long n, k = 1, factorial[21], p, used[21];
    
    factorial[0] = 1;
    for(int i = 1; i <= 20; i++)
    {
        factorial[i] = factorial[i-1] * i;
    }
    for(int i = 1; i <= 21; i++)
    {
        used[i] = 0;
    }
    
    std::cin >> n >> k;
    if(k == 1)
    {
        std::cin >> p;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(used[j] == 1)
                {
                    continue;
                }
                if(p <= factorial[n - i])
                {
                    std::cout << j << ' ';
                    used[j] = 1;
                    break;
                }
                p -= factorial[n - i];
            }
        }
    }
    else
    {
        long long cnt = 1;
        for(int i = 1; i <= n; i++)
        {
            std::cin >> p;
            for(int j = 1; j < p; j++)
            {
                if(used[j] == 1)
                {
                    continue;
                }
                cnt += factorial[n - i];
            }
            used[p] = 1;
        }
        std::cout << cnt;
    }
    std::cout << '\n';
    return 0;
}
