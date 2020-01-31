//
//  main.cpp
//  8979
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, k, idx, nations[1001][3], rank = 1;
    
    std::cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        std::cin >> idx;
        std::cin >> nations[idx][0] >> nations[idx][1] >> nations[idx][2];
    }
    for(int i = 1; i <= n; i++)
    {
        if(i == k)
        {
            continue;
        }
        if(nations[i][0] > nations[k][0])
        {
            rank++;
        }
        else if(nations[i][0] == nations[k][0])
        {
            if(nations[i][1] > nations[k][1])
            {
                rank++;
            }
            else if(nations[i][1] == nations[k][1])
            {
                if(nations[i][2] > nations[k][2])
                {
                    rank++;
                }
            }
        }
    }
    std::cout << rank << '\n';
    
    return 0;
}
