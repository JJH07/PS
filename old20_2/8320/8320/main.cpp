//
//  main.cpp
//  8320
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, cnt = 0;
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        if(i * i > n)
        {
            break;
        }
        for(int j = i; j <= n; j++)
        {
            if(i * j > n)
            {
                break;
            }
            cnt++;
        }
    }
    std::cout << cnt << '\n';
    return 0;
}
