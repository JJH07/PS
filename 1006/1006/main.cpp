//
//  main.cpp
//  1006
//
//  Created by 진준호 on 2020/02/10.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>

int strict[2][10001], dp[10001][2][2];
int n, w;
int solve(int idx, int in, int out)
{
    if(idx > n)
    {
        return 0;
    }
    int &ret = dp[idx][in][out];
    if(ret != -1)
    {
        return ret;
    }
    bool flag_in = false, flag_out = false;
    ret = in + out + solve(idx + 1, 1, 1);
    if(in && out && strict[0][idx] + strict[1][idx] <= w)
    {
        ret = std::min(ret, 1 + solve(idx + 1, 1, 1));
    }
    if(in && idx + 1 <= n && strict[0][idx] + strict[0][idx + 1] <= w)
    {
        ret = std::min(ret, in + out + solve(idx + 1, 0, 1));
        flag_in = true;
    }
    if(out && idx + 1 <= n && strict[1][idx] + strict[1][idx + 1] <= w)
    {
        ret = std::min(ret, in + out + solve(idx + 1, 1, 0));
        flag_out = true;
    }
    if(flag_in && flag_out)
    {
        ret = std::min(ret, 2 + solve(idx + 1, 0, 0));
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t, ans, keep_s[2], keep_e[2];
    
    std::cin >> t;
    while(t--)
    {
        std::cin >> n >> w;
        for(int i = 0; i < 2; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                std::cin >> strict[i][j];
            }
        }
        std::memset(dp, -1, sizeof(dp));
        ans = solve(1, 1, 1);
        
        if(n > 1)
        {
            keep_s[0] = strict[0][1];
            keep_s[1] = strict[1][1];
            keep_e[0] = strict[0][n];
            keep_e[1] = strict[1][n];
            if(keep_s[0] + keep_e[0] <= w)
            {
                strict[0][1] = w;
                strict[0][n] = w;
                std::memset(dp, -1, sizeof(dp));
                ans = std::min(ans, solve(1, 0, 1));
            }
            if(keep_s[1] + keep_e[1] <= w)
            {
                strict[0][1] = keep_s[0];
                strict[0][n] = keep_e[0];
                strict[1][1] = w;
                strict[1][n] = w;
                std::memset(dp, -1, sizeof(dp));
                ans = std::min(ans, solve(1, 1, 0));
            }
            if(keep_s[0] + keep_e[0] <= w && keep_s[1] + keep_e[1] <= w)
            {
                strict[0][1] = w;
                strict[0][n] = w;
                strict[1][1] = w;
                strict[1][n] = w;
                std::memset(dp, -1, sizeof(dp));
                ans = std::min(ans, solve(1, 0, 0));
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}
