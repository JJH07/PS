//
//  main.cpp
//  1670
//
//  Created by 진준호 on 2020/02/12.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
unsigned long long dp[10001];
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    
    dp[0] = 1;
    dp[2] = 1;
    for(int i = 4; i <= n; i += 2)
    {
        for(int j = 0; j <= i - 2; j += 2)
        {
            dp[i] = (dp[i] + dp[j] * dp[i - 2 - j]) % 987654321;
        }
    }
    std::cout << dp[n] << '\n';
    
    return 0;
}
