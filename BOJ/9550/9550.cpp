//
//  main.cpp
//  9550
//
//  Created by 진준호 on 2020/01/14.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T, n, k, p, ans;
    
    std::cin >> T;
    while(T--)
    {
        std::cin >> n >> k;
        ans = 0;
        while(n--)
        {
            std::cin >> p;
            ans += (p / k);
        }
        std::cout << ans << '\n';
    }
    
    return 0;
}
