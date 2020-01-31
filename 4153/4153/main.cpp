//
//  main.cpp
//  4153
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
    
    int x[3];
    
    while(1)
    {
        std::cin >> x[0] >> x[1] >> x[2];
        if(x[0] + x[1] + x[2] == 0)
        {
            break;
        }
        std::sort(x, x + 3);
        if(x[0] * x[0] + x[1] * x[1] == x[2] * x[2])
        {
            std::cout << "right\n";
        }
        else
        {
            std::cout << "wrong\n";
        }
    }
    return 0;
}
