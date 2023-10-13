//
//  main.cpp
//  1727
//
//  Created by 진준호 on 2020/02/19.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

int n, m, min_size, dp[1000][1000];
std::vector<int> a, b;

int solve(int ai, int bi)
{
    if(ai >= n || bi >= m)
    {
        return 0;
    }
    int &ret = dp[ai][bi];
    if(ret != -1)
    {
        return ret;
    }
    ret = 21470000;
    for(int i = 0; i <= (m - n) - (bi - ai); i++)
    {
        ret = std::min(ret, abs(a[ai] - b[bi]) + solve(ai + 1, bi + 1 + i));
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        std::cin >> tmp;
        a.push_back(tmp);
    }
    for(int i = 0; i < m; i++)
    {
        int tmp;
        std::cin >> tmp;
        b.push_back(tmp);
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    
    std::memset(dp, -1, sizeof(dp));
    
    if(n > m)
    {
        std::swap(a, b);
        std::swap(n, m);
    }
    int ans = 21470000;
    for(int i = 0; i <= m - n; i++)
    {
        ans = std::min(ans, solve(0, i));
    }
    std::cout << ans << '\n';
    return 0;
}
