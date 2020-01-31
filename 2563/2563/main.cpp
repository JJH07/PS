//
//  main.cpp
//  2563
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, a, b, map[100][100], ans = 0;
    
    std::fill(map[0], map[0] + 100 * 100, 0);
    
    std::cin >> n;
    
    while(n--)
    {
        std::cin >> a >> b;
        for(int i = a; i < a + 10; i++)
        {
            for(int j = b; j < b + 10; j++)
            {
                map[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            ans += map[i][j];
        }
    }
    std::cout << ans << '\n';
    return 0;
}
