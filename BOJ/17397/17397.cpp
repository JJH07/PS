//
//  main.cpp
//  17397
//
//  Created by 진준호 on 2020/05/11.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>

int n, m, out[1001], dp[1001][11][200];
int solve(int idx, int before, int money)
{
    if(idx > n)
    {
        return 0;
    }
    int &ret = dp[idx][before][money];
    if(ret != -1)
    {
        return ret;
    }
    int now = out[idx];
    if(before <= now)
    {
        ret = solve(idx + 1, now, money);
    }
    else
    {
        ret = (before - now) * (before - now) + solve(idx + 1, now, money);
        for(int i = before - now; i > 0; i--)
        {
            if(i > money)
            {
                continue;
            }
            ret = std::min(ret, (before - now - i) * (before - now - i) + solve(idx + 1, now + i, money - i));
        }
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::fill(dp[0][0], dp[0][0] + 1001 * 11 * 200, -1);

    std::cin >> n >> m;
    out[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> out[i];
    }
    std::cout << solve(1, 0, m) << '\n';
    
    return 0;
}
