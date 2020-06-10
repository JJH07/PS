//
//  main.cpp
//  2234
//
//  Created by 진준호 on 2020/05/20.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m;
    std::cin >> m >> n;
    int map[n + 1][m + 1], room_number[n + 1][m + 1], room_cnt = -1;
    std::vector<int> room_size;
    std::queue<std::pair<int, int>> q;
    
    std::fill(room_number[0], room_number[0] + (n + 1) * (m + 1), -1);
    
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
            if(room_number[i][j] == -1)
            {
                room_cnt++;
                room_size.push_back(1);
                room_number[i][j] = room_cnt;
                q.push({i, j});
                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int idx = 0; idx < 4; idx++)
                    {
                        int nx = dx[idx] + x;
                        int ny = dy[idx] + y;
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m || room_number[nx][ny] != -1)
                        {
                            continue;
                        }
                        if(map[x][y] & (1 << idx))
                        {
                            continue;
                        }
                        room_number[nx][ny] = room_cnt;
                        room_size[room_cnt]++;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    int biggest = -1, two_room = -1;
    for(int i = 0; i <= room_cnt; i++)
    {
        biggest = std::max(biggest, room_size[i]);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int idx = 0; idx < 4; idx++)
            {
                int nx = dx[idx] + i;
                int ny = dy[idx] + j;
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || room_number[nx][ny] == room_number[i][j])
                {
                    continue;
                }
                two_room = std::max(two_room, room_size[room_number[i][j]] + room_size[room_number[nx][ny]]);
            }
        }
    }
    std::cout << room_cnt + 1 << '\n' << biggest << '\n' << two_room << '\n';
    return 0;
}
