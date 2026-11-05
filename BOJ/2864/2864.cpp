//
//  main.cpp
//  2864
//
//  Created by 진준호 on 2019/12/30.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <climits>
int f1(int x)
{
    int val, ret = 0, i = 1;
    while(x > 0)
    {
        val = x % 10;
        if(val == 5)
        {
            val = 6;
        }
        ret += (val * i);
        x /= 10;
        i *= 10;
    }
    return ret;
}
int f2(int x)
{
    int val, ret = 0, i = 1;
    while(x > 0)
    {
        val = x % 10;
        if(val == 6)
        {
            val = 5;
        }
        ret += (val * i);
        x /= 10;
        i *= 10;
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int a, b;
    
    std::cin >> a >> b;
    
    std::cout << f2(a) + f2(b) << ' ' << f1(a) + f1(b) << '\n';
    return 0;
}
