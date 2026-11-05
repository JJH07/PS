//
//  main.cpp
//  4948
//
//  Created by 진준호 on 2020/01/21.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>

#define MAX_LEN 123456 * 2

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, list[MAX_LEN + 1];
    std::fill(list, list + MAX_LEN, 1);

    for(int i = 2; i <= MAX_LEN; i++)
    {
        if(list[i] == 1)
        {
            for(int j = i + i; j <= MAX_LEN; j += i)
            {
                list[j] = 0;
            }
        }
    }
    
    while(1)
    {
        std::cin >> n;
        if(n == 0)
        {
            break;
        }
        int cnt = 0;
        for(int i = n + 1; i <= (n * 2 > MAX_LEN ? MAX_LEN : n * 2); i++)
        {
            if(list[i])
            {
                cnt++;
            }
        }
        std::cout << cnt << '\n';
    }
    return 0;
}
