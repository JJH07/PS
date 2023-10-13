//
//  main.cpp
//  10569
//
//  Created by 진준호 on 2020/01/07.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t, v, e;
    
    std::cin >> t;
    while(t--)
    {
        std::cin >> v >> e;
        std::cout << 2 - v + e << '\n';
    }
    
    return 0;
}
