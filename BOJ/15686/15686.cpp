//
//  main.cpp
//  15686
//
//  Created by 진준호 on 2020/03/30.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

int n, m, picked_table[13], ans;
std::vector<std::pair<int, int>> home, chicken;
void pick(int picked, int idx)
{
    if(picked > 0)
    {
        int chicken_distance = 0;
        for(auto x : home)
        {
            int distance = 2147000;
            for(int i = 0; i < picked; i++)
            {
                distance = std::min(distance, std::abs(x.first - chicken[picked_table[i]].first) + std::abs(x.second - chicken[picked_table[i]].second));
            }
            chicken_distance += distance;
        }
        ans = std::min(ans, chicken_distance);
    }
    if(picked == m)
    {
        return;
    }
    int chicken_len = (int)chicken.size();
    for(int i = idx; i < chicken_len; i++)
    {
        picked_table[picked] = i;
        pick(picked + 1, i + 1);
        picked_table[picked] = 0;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int tmp;
            std::cin >> tmp;
            if(tmp == 1)
            {
                home.push_back(std::make_pair(i, j));
            }
            if(tmp == 2)
            {
                chicken.push_back(std::make_pair(i, j));
            }
        }
    }
    ans = 2147000;
    pick(0, 0);
    std::cout << ans << '\n';
    return 0;
}
