//
//  main.cpp
//  1072
//
//  Created by 진준호 on 2019/12/27.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int x, y;
    double z;
    
    std::cin >> x >> y;
    z = std::floor(100.0 * y / x);
    
    int l = 1, r = x;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        double nz = std::floor(100.0 * (y + mid) /(mid + x));
        if(nz == z)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    
    if(z != std::floor(100.0 * (y + l) / (x + l)))
    {
        std::cout << l << '\n';
    }
    else
    {
        std::cout << -1 << '\n';
    }
    return 0;
}
