//
//  main.cpp
//  2300
//
//  Created by 진준호 on 2020/02/21.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <climits>

int n, dp[10001];
std::vector<std::pair<int, int>> building;

int solve(int idx)
{
    if(idx >= n)
    {
        return 0;
    }
    int &ret = dp[idx];
    if(ret != -1)
    {
        return ret;
    }
    ret = INT_MAX;
    int y_len = 0, x_len = 0;
    for(int i = idx; i < n; i++)
    {
        y_len = std::max(y_len, abs(building[i].second));
        x_len = building[i].first - building[idx].first;
        ret = std::min(ret, std::max(y_len * 2, x_len) + solve(i + 1));
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::memset(dp, -1, sizeof(dp));
    
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        building.push_back(std::make_pair(a, b));
    }
    std::sort(building.begin(), building.end());
    
    std::cout << solve(0) << '\n';
    return 0;
}
