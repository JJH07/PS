//
//  main.cpp
//  1350
//
//  Created by 진준호 on 2020/01/14.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N;
    unsigned long long fsz[1000], cluster, tot = 0;
    
    std::cin >> N;
    for(int i = 0; i < N; i++)
    {
        std::cin >> fsz[i];
    }
    std::cin >> cluster;
    
    for(int i = 0; i < N; i++)
    {
        if(fsz[i] == 0)
        {
            continue;
        }
        else
        {
            tot += (fsz[i] / cluster) * cluster;
            if(fsz[i] % cluster)
            {
                tot += cluster;
            }
        }
    }
    std::cout << tot << '\n';
    
    return 0;
}
