//
//  main.cpp
//  1315
//
//  Created by 진준호 on 2020/03/03.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

struct quest{
    int STR;
    int INT;
    int PNT;
};
int n, memo[1001][1001];
std::vector<quest> quests;
int solve(int s, int i)
{
    int &ret = memo[s][i];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    int point = 0;
    for(int next = 0; next < n; next++)
    {
        if(s >= quests[next].STR || i >= quests[next].INT)
        {
            point += quests[next].PNT;
            ret++;
        }
    }
    for(int next = 0; next < n; next++)
    {
        if(quests[next].STR > s && point - s - i + 2 >= quests[next].STR - s)
        {
            ret = std::max(ret, solve(quests[next].STR, i));
        }
        if(quests[next].INT > i && point - s - i + 2 >= quests[next].INT - i)
        {
            ret = std::max(ret, solve(s, quests[next].INT));
        }
    }
    return ret;
}
bool comp(const quest &a, const quest &b)
{
    return (a.INT + a.STR) < (b.INT + b.STR);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(memo, -1, sizeof(memo));
    
    std::cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        quests.push_back({a, b, c});
    }
    std::sort(quests.begin(), quests.end(), comp);
    
    std::cout << solve(1, 1) << '\n';
    return 0;
}
