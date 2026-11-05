//
//  main.cpp
//  2655
//
//  Created by 진준호 on 2020/06/01.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
struct brick{
    int downsize;
    int height;
    int weight;
    int idx;
};
bool comp(const brick &x, const brick &y)
{
    return x.weight < y.weight;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    std::vector<brick> bricks(n + 1, {0, 0, 0, 0});
    std::vector<int> dp(n + 1, 0), before(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        std::cin >> bricks[i].downsize >> bricks[i].height >> bricks[i].weight;
        bricks[i].idx = i;
    }
    std::sort(bricks.begin(), bricks.end(), comp);
    
    int max_h = 0, max_idx = 0;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(bricks[i].downsize < bricks[j].downsize)
            {
                continue;
            }
            if(dp[i] < dp[j] + bricks[i].height)
            {
                dp[i] = dp[j] + bricks[i].height;
                before[i] = j;
            }
        }
        if(max_h < dp[i])
        {
            max_h = dp[i];
            max_idx = i;
        }
    }
    std::stack<int> track;
    while(max_idx > 0)
    {
        track.push(bricks[max_idx].idx);
        max_idx = before[max_idx];
    }
    
    std::cout << track.size() << '\n';
    while(!track.empty())
    {
        std::cout << track.top() << '\n';
        track.pop();
    }
    return 0;
}
