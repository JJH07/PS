//
//  main.cpp
//  1938
//
//  Created by 진준호 on 2020/05/21.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
struct node
{
    int x;
    int y;
    int state;
    int distance;
};
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int tdx[2][2] = {{0, 0}, {-1, 1}}, tdy[2][2] = {{-1, 1}, {0, 0}};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, start_state = 0, end_state = 0, visited[50][50][2], ans = 0;
    std::string map[50];
    std::vector<std::pair<int, int>> start, end;
    // 0이면 수평 1이면 수직
    std::queue<node> q;
    std::memset(visited, 0, sizeof(visited));
    
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> map[i];
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] == 'B')
            {
                start.push_back({i, j});
                map[i][j] = '0';
            }
            if(map[i][j] == 'E')
            {
                end.push_back({i, j});
                map[i][j] = '0';
            }
        }
    }
    if(start[0].first + 1 == start[1].first)
    {
        start_state = 1;
    }
    if(end[0].first + 1 == end[1].first)
    {
        end_state = 1;
    }
    
    q.push({start[1].first, start[1].second, start_state, 0});
    visited[start[1].first][start[1].second][start_state] = 1;
    
    while(!q.empty())
    {
        node front = q.front();
        q.pop();
        if(end[1].first == front.x && end[1].second == front.y && end_state == front.state)
        {
            ans = front.distance;
            break;
        }
        
        int sx = front.x - 1;
        int sy = front.y - 1;
        int ex = front.x + 1;
        int ey = front.y + 1;
        if(sx >= 0 && sy >= 0 && ex < n && ey < n && !visited[front.x][front.y][(front.state + 1) % 2])
        {
            int zero_count = 0;
            for(int i = sx; i <= ex; i++)
            {
                for(int j = sy; j <= ey; j++)
                {
                    if(map[i][j] == '0')
                    {
                        zero_count++;
                    }
                }
            }
            if(zero_count == 9)
            {
                visited[front.x][front.y][(front.state + 1) % 2] = 1;
                q.push({front.x, front.y, (front.state + 1) % 2, front.distance + 1});
            }
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + front.x;
            int ny = dy[i] + front.y;
            if(nx < 0 || ny < 0 || nx >= n || ny >= n || map[nx][ny] != '0' || visited[nx][ny][front.state])
            {
                continue;
            }
            int zero_count = 1;
            for(int j = 0; j < 2; j++)
            {
                int tnx = tdx[front.state][j] + nx;
                int tny = tdy[front.state][j] + ny;
                if(tnx < 0 || tny < 0 || tnx >= n || tny >= n || map[tnx][tny] != '0')
                {
                    break;
                }
                zero_count++;
            }
            if(zero_count == 3)
            {
                visited[nx][ny][front.state] = 1;
                q.push({nx, ny, front.state, front.distance + 1});
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}
