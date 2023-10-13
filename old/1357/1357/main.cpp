//
//  main.cpp
//  1357
//
//  Created by 진준호 on 2019/12/30.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
int rev(int x)
{
    int ret = 0;
    while(x > 0)
    {
        ret = ret * 10 + x % 10;
        x /= 10;
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int x, y;
    std::cin >> x >> y;
    
    std::cout << rev(rev(x) + rev(y)) << '\n';
    
    return 0;
}
