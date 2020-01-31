//
//  main.cpp
//  5032
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int e, f, c, sum = 0, get, ret;
    
    std::cin >> e >> f >> c;
    while(e + f >= c)
    {
        get = (e + f) / c;
        ret = (e + f) % c;
        sum += get;
        e = ret;
        f = get;
    }
    std::cout << sum << '\n';
    return 0;
}
