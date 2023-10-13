//
//  main.cpp
//  11006
//
//  Created by 진준호 on 2020/01/14.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T, n, m;
    
    std::cin >> T;
    while(T--)
    {
        std::cin >> n >> m;
        std::cout << 2 * m - n << ' ' << n - m << '\n';
    }
    
    return 0;
}
