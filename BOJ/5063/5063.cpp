//
//  main.cpp
//  5063
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, r, c, e;
    std::cin >> n;
    
    while(n--)
    {
        std::cin >> r >> c >> e;
        if(r < c - e)
        {
            std::cout << "advertise\n";
        }
        else if(r == c - e)
        {
            std::cout << "does not matter\n";
        }
        else
        {
            std::cout << "do not advertise\n";
        }
    }
    
    return 0;
}
