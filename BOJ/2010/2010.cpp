//
//  main.cpp
//  2010
//
//  Created by 진준호 on 2019/12/27.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, plug, tot = 1;
    
    std::cin >> n;
    
    while(n--)
    {
        std::cin >> plug;
        tot += plug - 1;
    }
    std::cout << tot << '\n';
    return 0;
}
