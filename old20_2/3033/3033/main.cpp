//
//  main.cpp
//  3033
//
//  Created by 진준호 on 2020/02/18.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

long long modv = 100007;
long long mod(long long number)
{
    if(number >= 0)
    {
        return number % modv;
    }
    return((-1 * number / modv + 1) * modv + number) % modv;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int L, l, m, r;
    std::string str, target;
    
    std::cin >> L >> str;
    l = 0;
    r = L;
    while(l + 1 < r)
    {
        long long hash = 0, p = 1;
        int change_left = false;
        std::vector<int> table[100007];
        
        m = (l + r) / 2;
    
        for(int i = 0; i < m; i++)
        {
            hash = mod(hash + (long long)str[m - i - 1] * p);
            if(i < m - 1)
            {
                p = mod(p * 2);
            }
        }
        for(int i = 0; i <= L - m; i++)
        {
            if(!table[hash].empty())
            {
                for(auto it : table[hash])
                {
                    bool FOUND = true;
                    for(int idx = 0; idx < m; idx++)
                    {
                        if(str[idx + i] != str[idx + it])
                        {
                            FOUND = false;
                            break;
                        }
                    }
                    if(FOUND)
                    {
                        change_left = true;
                        break;
                    }
                }
            }
            if(change_left)
            {
                break;
            }
            table[hash].push_back(i);
            hash = mod(2 * (hash - str[i] * (long long)p) + str[m + i]);
        }
        if(change_left)
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    std::cout << l << '\n';
    return 0;
}
