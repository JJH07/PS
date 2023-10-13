//
//  main.cpp
//  2355
//
//  Created by 진준호 on 2020/01/07.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cmath>
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    long long a, b, keep = 0, mid, cnt;
    
    std::cin >> a >> b;
    if(a > b)
    {
        std::swap(a, b);
    }
    if(a < 0)
    {
        keep = a * -1;
    }
    a += keep;
    b += keep;
    mid = (a + b) / 2 - keep;
    cnt = b - a + 1;
    if(cnt % 2 == 0)
    {
        std::cout << (mid + mid + 1) * (cnt / 2) << '\n';
    }
    else
    {
        std::cout << mid * cnt << '\n';
    }
    return 0;
}
