//
//  main.cpp
//  16234
//
//  Created by 진준호 on 2020/04/02.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>

struct nd{
    int x;
    int y;
};
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, l, r, map[51][51], united[1251], visited[51][51];
    
    std::cin >> n >> l >> r;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cin >> map[i][j];
        }
    }
    int ans = 0;
    while(1)
    {
        std::memset(united, 0, sizeof(united));
        std::memset(visited, 0, sizeof(visited));
        std::queue<nd> q;
        nd front;
        int union_counting = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(visited[i][j] == 0)
                {
                    int block_count = 1;
                    int sum = map[i][j];
                    
                    q.push({i, j});
                    visited[i][j] = union_counting;
                    
                    while(!q.empty())
                    {
                        front = q.front();
                        q.pop();
                        for(int i = 0; i < 4; i++)
                        {
                            int nx = dx[i] + front.x;
                            int ny = dy[i] + front.y;
                            if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] != 0)
                            {
                                continue;
                            }
                            int diff = std::abs(map[front.x][front.y] - map[nx][ny]);
                            if(diff >= l && diff <= r)
                            {
                                sum += map[nx][ny];
                                block_count++;
                                q.push({nx, ny});
                                visited[nx][ny] = union_counting;
                            }
                        }
                    }
                    if(block_count == 1)
                    {
                        visited[i][j] = 2501;
                    }
                    else
                    {
                        united[union_counting] = sum / block_count;
                        union_counting++;
                    }
                }
            }
        }
        if(union_counting == 1)
        {
            break;
        }
        ans++;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(visited[i][j] == 2501)
                {
                    continue;
                }
                map[i][j] = united[visited[i][j]];
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}
