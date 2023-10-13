//
//  main.cpp
//  1016
//
//  Created by 진준호 on 2019/12/30.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <cmath>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    bool visited[1000001];
    long long mn, mx, cnt = 0;
    for(int i = 0; i < 1000001; i++)
    {
        visited[i] = false;
    }
    std::cin >> mn >> mx;
    
    for(long long c = 2; c * c <= mx; c++)
    {
        long long len = mx / (c * c);
        for(long long p = mn / (c * c); p <= len; p++)
        {
            long long val = p * (c * c);
            if(val >= mn && val <= mx)
            {
                visited[val - mn] = true;
            }
        }
    }
    for(int i = 0; i < mx - mn + 1; i++)
    {
        if(visited[i] == false)
        {
            cnt++;
        }
    }
    std::cout << cnt << '\n';
    return 0;
}
