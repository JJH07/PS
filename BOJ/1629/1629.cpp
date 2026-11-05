//
//  main.cpp
//  1629
//
//  Created by 진준호 on 2019/12/30.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
unsigned long long func(unsigned long long x, unsigned long long y, unsigned long long z)
{
    if(y == 1)
    {
        return x;
    }
    return ((y % 2) ? x : 1) * func(x * x % z, y / 2, z) % z;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    unsigned long long a, b, c;
    
    std::cin >> a >> b >> c;
    
    std::cout << func(a % c, b, c) << '\n';
    
    return 0;
}
