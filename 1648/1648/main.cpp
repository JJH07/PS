//
//  main.cpp
//  1648
//
//  Created by 진준호 on 2020/02/14.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <set>

int n, m, dp[14][1 << 14];
int solve(int idx, int state)
{
    if(idx == n)
    {
        if(state == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int &ret = dp[idx][state];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    std::set<int> list;
    list.insert(state);
    for(auto it = list.begin(); it != list.end(); it++)
    {
        for(int i = 0; i < m - 1; i++)
        {
            if(!(*it & (1 << i)) & !(*it & (1 << (i + 1))))
            {
                list.insert(*it + (1 << i) + (1 << (i + 1)));
            }
        }
        int next = 0;
        for(int i = 0; i < m; i++)
        {
            if(!(*it & (1 << i)))
            {
                next += (1 << i);
            }
        }
        ret = (ret + solve(idx + 1, next)) % 9901;
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> m;

    std::memset(dp, -1, sizeof(dp));
    std::cout << solve(0, 0) <<  '\n';
    
    return 0;
}
