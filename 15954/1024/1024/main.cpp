//
//  main.cpp
//  1024
//
//  Created by 진준호 on 2019/12/31.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N, L, s, e, sum, idx, min_len = 1000000001, ms, me;
    std::cin >> N >> L;
    
    idx = 1;
    s = 0;
    e = 0;
    sum = 0;
    while(idx <= N + 1)
    {
        if(sum == N && (e - s + 1) < L)
        {
            break;
        }
        if(sum == N && (e - s + 1) >= L && min_len > (e - s + 1))
        {
            min_len = (e - s + 1);
            ms = s;
            me = e;
        }
        if(sum < N)
        {
            sum += idx;
            e = idx;
            idx++;
        }
        else
        {
            sum -= s;
            s++;
        }
    }
    if(min_len <= 100)
    {
        for(int i = ms; i <= me; i++)
        {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
    else
    {
        std::cout << "-1\n";
    }
    return 0;
}
