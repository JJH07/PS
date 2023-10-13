//
//  main.cpp
//  1789
//
//  Created by 진준호 on 2019/12/30.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    long long s, idx, cnt = 0;
    
    std::cin >> s;
    
    for(idx = 1; s - idx >= 0; idx++)
    {
        s -= idx;
        cnt++;
    }
    std::cout << cnt << '\n';
    return 0;
}
