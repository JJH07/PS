//
//  main.cpp
//  14500
//
//  Created by 진준호 on 2020/03/18.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <queue>

int n, m, map[501][501], max_v = 0;
int dx[4] = {-1, 1, 0}, dy[4] = {0, 0, 1};

void dfs(int x, int y, int bx, int by, int sum, int cnt)
{
    if(cnt == 4)
    {
        max_v = std::max(max_v, sum);
        return ;
    }
    if(cnt == 2)
    {
        for(int i = 0; i < 3; i++)
        {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if(x1 < 0 || y1 < 0 || x1 >= n || y1 >= m || (bx == x1 && by == y1))
            {
                continue;
            }
            for(int j = i + 1; j < 3; j++)
            {
                int x2 = x + dx[j];
                int y2 = y + dy[j];
                if(x2 < 0 || y2 < 0 || x2 >= n || y2 >= m || (bx == x2 && by == y2))
                {
                    continue;
                }
                max_v = std::max(max_v, sum + map[x1][y1] + map[x2][y2]);
            }
        }
    }
    for(int i = 0; i < 3; i++)
    {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx < 0 || ny < 0 || nx >= n || ny >= m || (nx == bx && ny == by))
        {
            continue;
        }
        dfs(nx, ny, x, y, sum + map[nx][ny], cnt + 1);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> m;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cin >> map[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            dfs(i, j, -1, -1, map[i][j], 1);
        }
    }
    std::cout << max_v << '\n';
    return 0;
}
