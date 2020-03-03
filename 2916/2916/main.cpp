//
//  main.cpp
//  2916
//
//  Created by 진준호 on 2020/03/03.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>

int n, k, all[361];
std::vector<int> chang;

void check(int c)
{
    if(all[c] == 1)
    {
        return ;
    }
    all[c] = 1;
    for(auto it : chang)
    {
        int next = c + it;
        if(next >= 360)
        {
            next -= 360;
        }
        check(next);
        next = c - it;
        if(next < 0)
        {
            next += 360;
        }
        check(next);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> k;
    
    for(int i = 0; i < n; i++)
    {
        int tmp;
        std::cin >> tmp;
        chang.push_back(tmp);
    }
    std::memset(all, 0, sizeof(all));
    check(0);
    for(int i = 0; i < k; i++)
    {
        int tmp;
        std::cin >> tmp;
        if(all[tmp])
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }
    
    
    return 0;
}
