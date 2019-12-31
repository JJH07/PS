//
//  main.cpp
//  1964
//
//  Created by 진준호 on 2019/12/31.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    long long n, cnt;
    
    std::cin >> n;
    
    cnt = (3 * n * n + 5 * n + 2) / 2 % 45678;
    std::cout << cnt << '\n';
    return 0;
}
