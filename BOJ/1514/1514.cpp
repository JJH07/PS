//
//  main.cpp
//  1514
//
//  Created by 진준호 on 2020/02/24.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
#include <cstring>

int n, dp[100][11][11][11], now[100], pw[100];
int solve(int idx, int a, int b, int c)
{
    if(idx >= n)
    {
        return 0;
    }
    int &ret = dp[idx][a][b][c];
    if(ret != -1)
    {
        return ret;
    }
    int rolling = 1;
    int d = (idx + 3 < n) ? now[idx + 3] : 10;
    if(a == pw[idx])
    {
        return solve(idx + 1, b, c, d);
    }
    if(std::min((10 + a - pw[idx]) % 10, (10 + pw[idx] - a) % 10) > 3)
    {
        rolling = 2;
    }
    
    ret = rolling + solve(idx + 1, b, c, d);
    for(int i = 1; i <= 3; i++)
    {
        ret = std::min(ret, 1 + solve(idx, (a + i) % 10, (b + i) % 10, c));
        ret = std::min(ret, 1 + solve(idx, (a + i) % 10, (b + i) % 10, (c + i) % 10));
        ret = std::min(ret, 1 + solve(idx, (10 + a - i) % 10, (10 + b - i) % 10, c));
        ret = std::min(ret, 1 + solve(idx, (10 + a - i) % 10, (10 + b - i) % 10, (10 + c - i) % 10));
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));
    
    std::string tmp;
    std::cin >> n;
    std::cin >> tmp;
    for(int i = 0; i < n; i++)
    {
        now[i] = (int)(tmp[i] - '0');
    }
    std::cin >> tmp;
    for(int i = 0; i < n; i++)
    {
        pw[i] = (int)(tmp[i] - '0');
    }
    std::cout << solve(0, now[0], now[1], now[2]) << '\n';
    return 0;
}
