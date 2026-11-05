//
//  main.cpp
//  1138
//
//  Created by 진준호 on 2020/01/07.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, line[11];

    for(int i = 1; i <= 10; i++)
    {
        line[i] = -1;
    }
    
    std::cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0, p;
        std::cin >> p;
        for(int j = 1; j <= n; j++)
        {
            if(line[j] != -1)
            {
                continue;
            }
            if(p > cnt)
            {
                cnt++;
            }
            else
            {
                line[j] = i;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        std::cout << line[i] << ' ';
    }
    return 0;
}
