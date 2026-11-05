//
//  main.cpp
//  3012
//
//  Created by 진준호 on 2020/05/22.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

int n;
long long memo[201][201];
char str[201];
char bracket_open[4] = {"({["}, bracket_close[4] = {")}]"};
long long solve(int start, int end)
{
    if(start > end)
    {
        return 1;
    }
    long long &ret = memo[start][end];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    for(int idx = start + 1; idx <= end; idx += 2)
    {
        for(int bidx = 0; bidx < 3; bidx++)
        {
            if((str[start] == bracket_open[bidx] || str[start] == '?') && (str[idx] == bracket_close[bidx] || str[idx] == '?'))
            {
                long long temp = solve(start + 1, idx - 1) * solve(idx + 1, end);
                ret += temp;
                if(ret > 100000)
                {
                    ret = (ret % 100000) + 1000000;
                }
            }
        }
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::fill(memo[0], memo[0] + 201 * 201, -1);

    scanf("%d", &n);
    scanf("%s", str);
    long long ans = solve(0, n - 1);
    if(ans > 100000)
    {
        ans %= 100000;
        printf("%05lld\n", ans);
    }
    else
    {
        printf("%lld\n", ans);
    }
    
    return 0;
}
