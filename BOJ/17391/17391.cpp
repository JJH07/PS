//
//  main.cpp
//  17391
//
//  Created by 진준호 on 2020/05/03.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>

int dx[4] = {0, 1}, dy[4] = {1, 0};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m, map[301][301], dist[301][301];
    std::queue<std::pair<int, int>> q;
    
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            std::cin >> map[i][j];
            dist[i][j] = 21470000;
        }
    }
    dist[1][1] = 0;
    q.push({1, 1});
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        if(x == n && y == m)
        {
            break;
        }
        q.pop();
        int booster = map[x][y];
        for(int i = 0; i < 2; i++)
        {
            for(int boost = 1; boost <= booster; boost++)
            {
                int nx = (dx[i] * boost) + x;
                int ny = (dy[i] * boost) + y;
                if(nx < 1 || ny < 1 || nx > n || ny > m)
                {
                    continue;
                }
                if(dist[x][y] + 1 >= dist[nx][ny])
                {
                    continue;
                }
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    std::cout << dist[n][m] << '\n';
    return 0;
}
