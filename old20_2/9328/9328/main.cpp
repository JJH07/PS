//
//  main.cpp
//  9328
//
//  Created by 진준호 on 2020/05/21.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int tc;
    std::cin >> tc;
    while(tc--)
    {
        int h, w, steal = 0;
        std::cin >> h >> w;
        std::string map[h], tmp;
        int visited[h][w], key_list[27];
        std::queue<std::pair<int, int>> q, door[27];
        std::memset(visited, 0, sizeof(visited));
        std::memset(key_list, 0, sizeof(key_list));
        
        for(int i = 0; i < h; i++)
        {
            std::cin >> map[i];
        }
        for(int i = 0; i < h; i++)
        {
            if(map[i][0] != '*')
            {
                q.push({i, 0});
                visited[i][0] = 1;
            }
            if(map[i][w - 1] != '*')
            {
                q.push({i, w - 1});
                visited[i][w - 1] = 1;
            }
        }
        for(int i = 1; i < w - 1; i++)
        {
            if(map[0][i] != '*')
            {
                q.push({0, i});
                visited[0][i] = 1;
            }
            if(map[h - 1][i] != '*')
            {
                q.push({h - 1, i});
                visited[h - 1][i] = 1;
            }
        }
        std::cin >> tmp;
        if(tmp[0] != '0')
        {
            for(char x : tmp)
            {
                key_list[x - 'a'] = 1;
            }
        }
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(map[x][y] == '$')
            {
                steal++;
            }
            if(map[x][y] >= 'A' && map[x][y] <= 'Z')
            {
                int idx = map[x][y] - 'A';
                if(key_list[idx])
                {
                    map[x][y] = '.';
                }
                else
                {
                    door[idx].push({x, y});
                    continue;
                }
            }
            if(map[x][y] >= 'a' && map[x][y] <= 'z')
            {
                int idx = map[x][y] - 'a';
                key_list[idx] = 1;
                map[x][y] = '.';
                while(!door[idx].empty())
                {
                    q.push({door[idx].front().first, door[idx].front().second});
                    door[idx].pop();
                }
            }
            
            for(int i = 0; i < 4; i++)
            {
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                if(nx < 0 || ny < 0 || nx >= h || ny >= w || map[nx][ny] == '*' || visited[nx][ny])
                {
                    continue;
                }
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
        std::cout << steal << '\n';
    }
    
    return 0;
}
