//
//  main.cpp
//  17392
//
//  Created by 진준호 on 2020/05/05.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, h[1001], max_len = 0;
    
    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        std::cin >> h[i];
        max_len += (h[i] + 1);
    }
    if(max_len >= m)
    {
        std::cout << "0\n";
    }
    else if(max_len == m - 1)
    {
        std::cout << "1\n";
    }
    else if(max_len == m - 2)
    {
        std::cout << "2\n";
    }
    else
    {
        int k = n + 1;
        int d = m - max_len;
        int t = d / k;

        int ans = (t * (t + 1) * (2 * t + 1) / 6) * k;
        ans += (d % k) * (t + 1) * (t + 1);
        std::cout << ans << '\n';
    }
    
    return 0;
}
