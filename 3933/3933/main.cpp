//
//  main.cpp
//  3933
//
//  Created by 진준호 on 2020/02/17.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>

int max_len = 2 << 15;
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, dp[max_len][5], idx = 1;
    std::memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    while(idx * idx < max_len)
    {
        for(int i = 0; i < max_len; i++)
        {
            if(i + idx * idx >= max_len)
            {
                break;
            }
            for(int j = 1; j <= 4; j++)
            {
                dp[i + idx * idx][j] += dp[i][j - 1];
            }
        }
        idx++;
    }
    while(1)
    {
        std::cin >> n;
        if(n == 0)
        {
            break;
        }
        std::cout << dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4] << '\n';
    }
    
    return 0;
}
