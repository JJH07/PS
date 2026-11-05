//
//  main.cpp
//  17395
//
//  Created by 진준호 on 2020/05/08.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cstring>

long long x[51], ans[51], min_v = 10000000000000001;
void dfs(int x_idx, int N, int count, long long bin_p)
{
    if(x_idx == N)
    {
        long long val, mn = 10000000000000001, mx = -1;
        for(int i = 0; i < N; i++)
        {
            val = x[i] - x[i + 1];
            mn = std::min(val, mn);
            mx = std::max(val, mx);
        }
        if(min_v > mx - mn)
        {
            min_v = mx - mn;
            for(int i = 0; i <= N; i++)
            {
                ans[i] = x[i];
            }
        }
        return;
    }
    long long tmp = x[x_idx - 1];
    for(long long i = bin_p; i >= 1; i /= 2)
    {
        if(N - x_idx == count)
        {
            break;
        }
        if(tmp >= i)
        {
            tmp -= i;
            count--;
            x[x_idx] = tmp;
            dfs(x_idx + 1, N, count, i / 2);
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, count = 0;
    long long start_p = -1;
    
    std::cin >> x[0] >> n;
    
    long long tmp = x[0];
    for(int i = 53; i >= 0; i--)
    {
        long long p = 1;
        p = p << i;
        if(tmp >= p)
        {
            if(start_p == -1)
            {
                start_p = p;
            }
            count++;
            tmp -= p;
        }
    }
    if(count >= n)
    {
        dfs(1, n, count, start_p);
        for(int i = 1; i <= n; i++)
        {
            std::cout << ans[i] << ' ';
        }
    }
    else
    {
        std::cout << "-1";
    }
    std::cout << '\n';
//
//    long long y = 1;
//    for(int i = 0; i < 16; i++)
//    {
//        y *= 10;
//    }
//    std::cout << y << '\n';
//    std::cout << count << '\n';
    
    return 0;
}
