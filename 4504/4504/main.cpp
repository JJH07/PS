//
//  main.cpp
//  4504
//
//  Created by 진준호 on 2019/12/31.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, p;
    
    std::cin >> n;
    while(1)
    {
        std::cin >> p;
        if(p == 0)
        {
            break;
        }
        if(p % n)
        {
            std::cout << p << " is NOT a multiple of " << n << ".\n";
        }
        else
        {
            std::cout << p << " is a multiple of " << n << ".\n";
        }
    }
    return 0;
}
