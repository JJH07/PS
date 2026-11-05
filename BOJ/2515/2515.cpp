//
//  main.cpp
//  2515
//
//  Created by 진준호 on 2020/01/29.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

int n, s, dp[300001], jump[300001];
std::vector<std::pair<int, int>> art;
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::fill(dp, dp + 300001, 0);
    
    int H, C, jump_idx = 0;
    std::cin >> n >> s;
    art.push_back(std::make_pair(0, 0));
    for(int i = 0; i < n; i++)
    {
        std::cin >> H >> C;
        art.push_back(std::make_pair(H, C));
    }
    std::sort(art.begin(), art.end());
    
    for(int i = 1; i <= n; i++)
    {
        while(1)
        {
            if(art[i].first - art[jump_idx + 1].first < s)
            {
                break;
            }
            jump_idx++;
        }
        dp[i] = std::max(dp[i-1], dp[jump_idx] + art[i].second);
    }
    std::cout << dp[n] << '\n';
    return 0;
}
