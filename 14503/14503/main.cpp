//
//  main.cpp
//  14503
//
//  Created by 진준호 on 2020/03/18.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cstring>
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m, x, y, dir, map[51][51], cleaned[51][51], tot_clean = 0;
    
    std::memset(cleaned, 0, sizeof(cleaned));
    
    std::cin >> n >> m >> x >> y >> dir;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cin >> map[i][j];
        }
    }
    while(1)
    {
        bool FLAG_NEXT = false;
        if(cleaned[x][y] == 0)
        {
            cleaned[x][y] = 1;
            tot_clean++;
        }
        for(int i = 0; i < 4; i++)
        {
            int ndir = (dir + 3 - i) % 4;
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];
            if(nx < 1 || ny < 1 || nx >= n - 1 || ny >= m - 1 || map[nx][ny] || cleaned[nx][ny])
            {
                continue;
            }
            FLAG_NEXT = true;
            dir = ndir;
            x = nx;
            y = ny;
            break;
        }
        if(FLAG_NEXT)
        {
            continue;
        }
        int nx = x + dx[(dir + 2) % 4];
        int ny = y + dy[(dir + 2) % 4];
        if(nx < 1 || ny < 1 || nx >= n - 1 || ny >= m - 1 || map[nx][ny])
        {
            break;
        }
        x = nx;
        y = ny;
    }
    std::cout << tot_clean << '\n';
    return 0;
}
