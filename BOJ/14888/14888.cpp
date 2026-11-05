//
//  main.cpp
//  14888
//
//  Created by 진준호 on 2020/03/18.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <climits>

int n, number[11], op_cnt[4], max_v, min_v;
void dfs(int idx, int sum, int a, int b, int c, int d)
{
    if(idx == n)
    {
        max_v = std::max(max_v, sum);
        min_v = std::min(min_v, sum);
        return ;
    }
    if(a < op_cnt[0])
    {
        dfs(idx + 1, sum + number[idx], a + 1, b, c, d);
    }
    if(b < op_cnt[1])
    {
        dfs(idx + 1, sum - number[idx], a, b + 1, c, d);
    }
    if(c < op_cnt[2])
    {
        dfs(idx + 1, sum * number[idx], a, b, c + 1, d);
    }
    if(d < op_cnt[3])
    {
        dfs(idx + 1, sum / number[idx], a, b, c, d + 1);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> number[i];
    }
    for(int i = 0; i < 4; i++)
    {
        std::cin >> op_cnt[i];
    }
    max_v = INT_MIN;
    min_v = INT_MAX;
    dfs(1, number[0], 0, 0, 0, 0);
    std::cout << max_v << '\n' << min_v << '\n';
    return 0;
}
