//
//  main.cpp
//  2822
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

bool compare(const std::pair<int, int> &x, const std::pair<int, int> &y)
{
    return x.first > y.first;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::vector<std::pair<int, int>> points;
    std::vector<int> lists;
    int ans = 0;
    
    for(int i = 1; i <= 8; i++)
    {
        int score;
        std::cin >> score;
        points.push_back(std::make_pair(score, i));
    }
    sort(points.begin(), points.end(), compare);
    for(int i = 0; i < 5; i++)
    {
        ans += points[i].first;
        lists.push_back(points[i].second);
    }
    sort(lists.begin(), lists.end());
    
    std::cout << ans << '\n';
    for(std::vector<int>::iterator it = lists.begin(); it != lists.end(); it++)
    {
        std::cout << *it << ' ';
    }
    
    return 0;
}
