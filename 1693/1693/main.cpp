//
//  main.cpp
//  1693
//
//  Created by 진준호 on 2020/02/12.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <cstring>

int n, dp[100001][31], col_max;
std::vector<int> conn[100001];
int go(int now, int parent, int color)
{
    if(now > 1 && (int)conn[now].size() == 1)
    {
        return color;
    }
    int &ret = dp[now][color];
    if(ret != -1)
    {
        return ret;
    }
    ret = color;
    for(auto it = conn[now].begin(); it != conn[now].end(); it++)
    {
        if(*it == parent)
        {
            continue;
        }
        int tmp = INT_MAX;
        for(int i = 1; i <= col_max; i++)
        {
            if(color == i)
            {
                continue;
            }
            tmp = std::min(tmp, go(*it, now, i));
        }
        ret += tmp;
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::memset(dp, -1, sizeof(dp));
    
    std::cin >> n;
    col_max = (int)log2(n);
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        std::cin >> a >> b;
        conn[a].push_back(b);
        conn[b].push_back(a);
    }
    int ans = INT_MAX;
    for(int i = 1; i <= col_max; i++)
    {
        ans = std::min(ans, go(1, 0, i));
    }
    std::cout << ans << '\n';
    std::cout << '\n' << (int)log2(100001) << '\n';
    return 0;
}
