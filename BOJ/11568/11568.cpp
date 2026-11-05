//
//  main.cpp
//  11568
//
//  Created by 진준호 on 2020/01/29.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, dp[1001], cards[1001];
    
    std::fill(dp, dp + 1001, 0);
    
    std::cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        std::cin >> cards[i];
    }
    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(cards[j] < cards[i])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans = std::max(ans, dp[i]);
    }
    std::cout << ans << '\n';
    return 0;
}
