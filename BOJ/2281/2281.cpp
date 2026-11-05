//
//  main.cpp
//  2281
//
//  Created by 진준호 on 2020/02/24.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
int n, m, len[1000], dp[1001][1001];
int solve(int idx, int size)
{
    if(idx == n)
    {
        return 0;
    }
    int &ret = dp[idx][size];
    if(ret != -1)
    {
        return ret;
    }
    ret = 21470000;
    int blank = 0;
    if(size > 0)
    {
        blank = 1;
    }
    if(blank + size + len[idx] > m)
    {
        return ret = (m - size) * (m - size) + solve(idx + 1, len[idx]);
    }
    ret = std::min(solve(idx + 1, size + blank + len[idx]), (m - size) * (m - size) + solve(idx + 1, len[idx]));
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));
    
    std::cin >> n >> m;
    
    for(int i = 0; i < n; i++)
    {
        std::cin >> len[i];
    }
    
    std::cout << solve(0, 0) << '\n';
    return 0;
}
