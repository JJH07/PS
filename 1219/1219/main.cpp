//
//  main.cpp
//  1219
//
//  Created by 진준호 on 2020/02/12.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <climits>

int n, s, d, m;
std::vector<std::pair<int, int>> vehicle[101];
std::vector<int> income, dist;
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> s >> d >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, p;
        std::cin >> a >> b >> p;
        vehicle[a].push_back(std::make_pair(b, p));
    }
    for(int i = 0; i < n; i++)
    {
        int p;
        std::cin >> p;
        income.push_back(p);
    }
    dist.resize(n + 1, INT_MIN);
    
    return 0;
}
