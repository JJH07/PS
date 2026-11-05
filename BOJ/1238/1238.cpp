//
//  main.cpp
//  1238
//
//  Created by 진준호 on 2020/05/12.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m, x, table[1001][1001];
    std::fill(table[0], table[0] + 1001 * 1001, 2147000);
    
    
    std::cin >> n >> m >> x;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        table[a][b] = c;
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(table[i][j] > table[i][k] + table[k][j])
                {
                    table[i][j] = table[i][k] + table[k][j];
                }
            }
        }
    }
    int max_dist = -1;
    for(int i = 1; i <= n; i++)
    {
        if(i == x)
        {
            continue;
        }
        if(table[i][x] == 2147000 || table[x][i] == 2147000)
        {
            continue;
        }
        max_dist = std::max(max_dist, table[i][x] + table[x][i]);
    }
    std::cout << max_dist << '\n';
    return 0;
}
