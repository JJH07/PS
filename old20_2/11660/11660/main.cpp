//
//  main.cpp
//  11660
//
//  Created by 진준호 on 2020/04/17.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cstring>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m, tot[1025][1025];
    
    std::memset(tot, 0, sizeof(tot));
    
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int tmp;
            std::cin >> tmp;
            tot[i][j] = tot[i][j - 1] + tmp;
        }
        for(int j = 1; j <= n; j++)
        {
            tot[i][j] += tot[i - 1][j];
        }
    }
    for(int idx = 0; idx < m; idx++)
    {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << tot[x2][y2] - tot[x2][y1 - 1] - tot[x1 - 1][y2] + tot[x1 - 1][y1 - 1] << '\n';
    }
    
    return 0;
}
