//
//  main.cpp
//  14889
//
//  Created by 진준호 on 2020/03/20.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cmath>

int n, table[21][21], visited[21], ans = 200000000;

void dfs(int idx, int cnt)
{
    if(n - idx < n / 2 - cnt)
    {
        return ;
    }
    if(cnt == n / 2)
    {
        int state = 0, link = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                {
                    continue;
                }
                if(visited[i] == 0 && visited[j] == 0)
                {
                    link += table[i][j];
                }
                if(visited[i] == 1 && visited[j] == 1)
                {
                    state += table[i][j];
                }
            }
        }
        ans = std::min(ans, abs(state - link));
        return ;
    }
    for(int i = idx; i < n; i++)
    {
        visited[i] = 1;
        dfs(i + 1, cnt + 1);
        visited[i] = 0;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cin >> table[i][j];
        }
    }
    dfs(0, 0);
    std::cout << ans << '\n';
    return 0;
}
