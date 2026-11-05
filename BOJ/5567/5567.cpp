//
//  main.cpp
//  5567
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m, a, b, list[501], cnt = 0;
    std::vector<int> friends[501];
    
    std::fill(list, list + 501, 0);
    
    std::cin >> n >> m;
    
    for(int i = 0; i < m; i++)
    {
        std::cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    for(std::vector<int>::iterator it = friends[1].begin(); it != friends[1].end(); it++)
    {
        if(list[*it] == 0)
        {
            list[*it] = 1;
            cnt++;
        }
        for(std::vector<int>::iterator invite = friends[*it].begin(); invite != friends[*it].end(); invite++)
        {
            if(*invite == 1 || list[*invite] == 1)
            {
                continue;
            }
            list[*invite] = 1;
            cnt++;
        }
    }
    std::cout << cnt << '\n';
    return 0;
}
