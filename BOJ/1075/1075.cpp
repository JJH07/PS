//
//  main.cpp
//  1075
//
//  Created by 진준호 on 2019/12/30.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, f;
    
    std::cin >> n >> f;
    
    for(int i = (n / 100) * 100; i <= n + f; i++)
    {
        if(i % f == 0)
        {
            n = i;
            break;
        }
    }
    
    n %= 100;
    if(n < 10)
    {
        std::cout << 0;
    }
    std::cout << n << '\n';
    return 0;
}
