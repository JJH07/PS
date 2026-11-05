//
//  main.cpp
//  1834
//
//  Created by 진준호 on 2019/12/31.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    long long N, ans = 0;

    std::cin >> N;
    
    for(long long i = 1; i <= N - 1; i++)
    {
        ans += N * i + i;
    }
    std::cout << ans << '\n';
    
    return 0;
}
