//
//  main.cpp
//  1507
//
//  Created by 진준호 on 2020/05/01.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cstring>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, dist[21][21], sum = 0;
    
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cin >> dist[i][j];
        }
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(i == k || dist[i][k] == 0)
            {
                continue;
            }
            for(int j = 1; j <= n; j++)
            {
                if(k == j || i == j || dist[k][j] == 0)
                {
                    continue;
                }
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    std::cout << "-1\n";
                    return 0;
                }
                if(dist[i][k] + dist[k][j] == dist[i][j])
                {
                    dist[i][j] = 0;
                }
                
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            sum += dist[i][j];
        }
    }
    std::cout << sum / 2 << '\n';
    return 0;
}
