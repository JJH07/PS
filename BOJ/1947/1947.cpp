//
//  main.cpp
//  1947
//
//  Created by 진준호 on 2020/01/29.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    unsigned long long n, dp[1000001];
    
    std::cin >> n;
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3; i <= n; i++)
    {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % 1000000000;
    }
    std::cout << dp[n] << '\n';
    return 0;
}
