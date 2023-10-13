//
//  main.cpp
//  17472
//
//  Created by 진준호 on 2020/04/23.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

int n, m, map[10][10], visited[10][10], island_count;
int distance[7][7];
int check()
{
    std::queue<std::pair<int, int>> q;
    q.push({0, 2});
    int ans = 2147000;
    while(!q.empty())
    {
        std::pair<int, int> front = q.front();
        int tot = front.first;
        int state = front.second;
        q.pop();
        int count = 0;
        for(int i = 1; i <= island_count; i++)
        {
            if(state & (1 << i))
            {
                count++;
            }
        }
        if(count == island_count)
        {
            ans = std::min(ans, tot);
        }
        for(int i = 2; i <= island_count; i++)
        {
            if(!(state & (1 << i)))
            {
                for(int j = 1; j <= island_count; j++)
                {
                    if(i == j)
                    {
                        continue;
                    }
                    if((state & (1 << j)) && distance[i][j] != 2147000)
                    {
                        q.push({tot + distance[i][j], state + (1 << i)});
                    }
                }
            }
        }
    }
    return ans;
}
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::memset(visited, 0, sizeof(visited));
    std::fill(distance[0], distance[0] + 7 * 7, 2147000);
    
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
            if(map[i][j] > 0 && visited[i][j] == 0)
            {
                std::queue<std::pair<int, int>> q;
                
                island_count++;
                visited[i][j] = 1;
                map[i][j] = island_count;
                q.push({i, j});
                while(!q.empty())
                {
                    std::pair<int, int> front = q.front();
                    q.pop();
                    for(int ni = 0; ni < 4; ni++)
                    {
                        int nx = dx[ni] + front.first;
                        int ny = dy[ni] + front.second;
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || map[nx][ny] == 0)
                        {
                            continue;
                        }
                        visited[nx][ny] = 1;
                        map[nx][ny] = island_count;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] > 0)
            {
                for(int ni = 0; ni < 2; ni++)
                {
                    int nx = dx[ni] + i;
                    int ny = dy[ni] + j;
                    int len = 1;
                    while(nx < n && ny < m)
                    {
                        if(map[nx][ny] > 0)
                        {
                            break;
                        }
                        nx += dx[ni];
                        ny += dy[ni];
                        len++;
                    }
                    if(nx == n || ny == m || len <= 2)
                    {
                        continue;
                    }
                    if(map[nx][ny] > 0 && map[i][j] != map[nx][ny])
                    {
                        distance[map[nx][ny]][map[i][j]] = std::min(len - 1, distance[map[nx][ny]][map[i][j]]);
                        distance[map[i][j]][map[nx][ny]] = std::min(len - 1, distance[map[i][j]][map[nx][ny]]);
                    }
                }
            }
        }
    }
    int ans = check();
    if(ans == 2147000)
    {
        std::cout << "-1\n";
    }
    else
    {
        std::cout << ans << '\n';
    }
    return 0;
}
