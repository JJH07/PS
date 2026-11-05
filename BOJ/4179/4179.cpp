//
//  main.cpp
//  4179
//
//  Created by 진준호 on 2020/05/21.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <queue>
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int r, c, ans = 0;
    std::string map[1000];
    std::queue<std::pair<int, int>> fire_q, escape_q;
    int fire_route[1000][1000], escape_route[1000][1000];
    std::memset(fire_route, 0, sizeof(fire_route));
    std::memset(escape_route, 0, sizeof(escape_route));
    
    std::cin >> r >> c;
    for(int i = 0; i < r; i++)
    {
        std::cin >> map[i];
        for(int j = 0; j < c; j++)
        {
            if(map[i][j] == 'J')
            {
                escape_q.push({i, j});
                escape_route[i][j] = 1;
            }
            if(map[i][j] == 'F')
            {
                fire_q.push({i, j});
                fire_route[i][j] = 1;
            }
        }
    }
    while(!fire_q.empty())
    {
        int x = fire_q.front().first;
        int y = fire_q.front().second;
        fire_q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx < 0 || ny < 0 || nx >= r || ny >= c || map[nx][ny] == '#' || fire_route[nx][ny] > 0)
            {
                continue;
            }
            fire_route[nx][ny] = fire_route[x][y] + 1;
            fire_q.push({nx, ny});
        }
    }
    while(!escape_q.empty())
    {
        int x = escape_q.front().first;
        int y = escape_q.front().second;
        escape_q.pop();
        if(x == 0 || y == 0 || x == r - 1 || y == c - 1)
        {
            ans = escape_route[x][y];
            break;
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx < 0 || ny < 0 || nx >= r || ny >= c || map[nx][ny] == '#' || escape_route[nx][ny] > 0)
            {
                continue;
            }
            if(fire_route[nx][ny] > 0 && fire_route[nx][ny] <= escape_route[x][y] + 1)
            {
                continue;
            }
            escape_route[nx][ny] = escape_route[x][y] + 1;
            escape_q.push({nx, ny});
        }
    }
    if(ans)
    {
        std::cout << ans << '\n';
    }
    else
    {
        std::cout << "IMPOSSIBLE\n";
    }
    return 0;
}
