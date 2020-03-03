//
//  main.cpp
//  2159
//
//  Created by 진준호 on 2020/03/03.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>

unsigned long long n, sx, sy, memo[100000][5];
int dx[5] = {0, 1, 0, -1, 0}, dy[5] = {0, 0, 1, 0, -1};
std::vector<std::pair<int, int>> list;

unsigned long long solve(int idx, int way)
{
    if(idx >= n)
    {
        return 0;
    }
    unsigned long long &ret = memo[idx][way];
    if(ret != -1)
    {
        return ret;
    }
    ret = LLONG_MAX;
    int x = list[idx].first + dx[way];
    int y = list[idx].second + dy[way];
    for(int i = 0; i < 5; i++)
    {
        int nx = dx[i] + list[idx + 1].first;
        int ny = dy[i] + list[idx + 1].second;
        if(nx <= 0 || ny <= 0 || nx >= 100001 || ny >= 100001)
        {
            continue;
        }
        ret = std::min(ret, abs(x - nx) + abs(y - ny) + solve(idx + 1, i));
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(memo, -1, sizeof(memo));
    
    std::cin >> n;
    for(int i = 0; i <= n; i++)
    {
        int tx, ty;
        std::cin >> tx >> ty;
        list.push_back(std::make_pair(tx, ty));
    }
    std::cout << solve(0, 0) << '\n';
    
    return 0;
}
