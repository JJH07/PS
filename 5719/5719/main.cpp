//
//  main.cpp
//  5719
//
//  Created by 진준호 on 2019/12/04.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
struct road{
    int n;
    int len;
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m, s, d;
    std::vector<road> list[501];
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    while(1)
    {
        std::cin >> n >> m;
        if(n == 0 && m == 0)
        {
            break;
        }
        std::cin >> s >> d;
        int u, v, p;
        for(int i = 0; i < m; i++)
        {
            std::cin >> u >> v >> p;
            list[u].push_back({v, p});
        }
    }
    
    
    return 0;
}
