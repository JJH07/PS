//
//  main.cpp
//  5721
//
//  Created by 진준호 on 2020/02/12.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m;
    while(1)
    {
        std::cin >> n >> m;
        if(n == 0 && m == 0)
        {
            break;
        }
        int dp[n][m];
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                std::cin >> dp[i][j];
            }
        }
        for(int i = 0; i < n; i++)
        {
            dp[i][1] = std::max(dp[i][0], dp[i][1]);
            for(int j = 2; j < m; j++)
            {
                dp[i][j] = std::max(dp[i][j - 2] + dp[i][j], dp[i][j - 1]);
            }
        }
        dp[1][m - 1] = std::max(dp[0][m - 1], dp[1][m - 1]);
        for(int i = 2; i < n; i++)
        {
            dp[i][m - 1] = std::max(dp[i - 2][m - 1] + dp[i][m - 1], dp[i - 1][m - 1]);
        }
        std::cout << dp[n-1][m-1] << '\n';
    }
    return 0;
}
