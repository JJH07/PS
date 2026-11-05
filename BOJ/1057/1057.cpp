//
//  main.cpp
//  1057
//
//  Created by 진준호 on 2019/12/27.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, a, b, round = 0;
    
    std::cin >> n >> a >> b;
    
    if(a > b)
    {
        std::swap(a, b);
    }
    while(a > 0)
    {
        round++;
        if(a % 2 == 1 && a + 1 == b)
        {
            break;
        }
        a = (a % 2) ? a / 2 + 1 : a / 2;
        b = (b % 2) ? b / 2 + 1 : b / 2;
    }
    if(a == 0)
    {
        std::cout << -1 << '\n';
    }
    else
    {
        std::cout << round << '\n';
    }
    return 0;
}
