//
//  main.cpp
//  5427
//
//  Created by 진준호 on 2019/11/26.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

char map[1001][1001];
int w, h, fire_map[1001][1001], visited[1001][1001];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
struct pos{
    int x;
    int y;
    int time;
};
pos front;
std::queue<pos> q;

void init_fire_map()
{
    std::fill(visited[0], visited[0] + 1001 * 1001, 0);
    std::fill(fire_map[0], fire_map[0] + 1001 * 1001, INT_MAX);
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(map[i][j] == '#')
            {
                visited[i][j] = 1;
            }
            else if(map[i][j] == '*')
            {
                q.push({i, j, 0});
                visited[i][j] = 1;
            }
        }
    }
    while(!q.empty())
    {
        front = q.front();
        fire_map[front.x][front.y] = front.time;
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nx = front.x + dx[i];
            int ny = front.y + dy[i];
            if(nx < 0 || ny < 0 || nx >= h || ny >= w || visited[nx][ny] == 1)
            {
                continue;
            }
            q.push({nx, ny, front.time + 1});
            visited[nx][ny] = 1;
        }
    }
}
int escape()
{
    std::fill(visited[0], visited[0] + 1001 * 1001, 0);
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(map[i][j] == '@')
            {
                q.push({i, j, 0});
                visited[i][j] = 1;
            }
            else if(map[i][j] == '#')
            {
                visited[i][j] = 1;
            }
        }
    }
    while(!q.empty())
    {
        front = q.front();
        q.pop();
        if(front.x == 0 || front.x == h-1 || front.y == 0 || front.y == w-1)
        {
            return front.time + 1;
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = front.x + dx[i];
            int ny = front.y + dy[i];
            if(nx < 0 || ny < 0 || nx >= h || ny >= w || visited[nx][ny] == 1)
            {
                continue;
            }
            if(fire_map[nx][ny] <= front.time + 1)
            {
                continue;
            }
            q.push({nx, ny, front.time + 1});
            visited[nx][ny] = 1;
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    int t;
    
    std::cin >> t;
    while(t--)
    {
        std::cin >> w >> h;
        for(int i = 0; i < h; i++)
        {
            std::cin >> map[i];
        }
        init_fire_map();
        int ans = escape();
        if(ans == -1)
        {
            std::cout << "IMPOSSIBLE\n";
        }
        else
        {
            std::cout << ans << '\n';
        }
    }
    return 0;
}
