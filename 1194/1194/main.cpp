//
//  main.cpp
//  1194
//
//  Created by 진준호 on 2020/05/20.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <cstring>
struct node
{
    int x;
    int y;
    int dist;
    int key;
};
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m, visited[50][50][1 << 6], ans = -1;
    std::string map[50];
    std::queue<node> q;
    node front = {0, 0, 0, 0};
    
    std::memset(visited, 0, sizeof(visited));
    
    std::cin >> n >> m;
    
    for(int i = 0; i < n; i++)
    {
        std::cin >> map[i];
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] == '0')
            {
                front.x = i;
                front.y = j;
            }
        }
    }
    
    visited[front.x][front.y][front.key] = 1;
    q.push(front);
    while(!q.empty())
    {
        front = q.front();
        q.pop();
        if(map[front.x][front.y] == '1')
        {
            ans = front.dist;
            break;
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + front.x;
            int ny = dy[i] + front.y;
            int nkey = front.key;
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == '#')
            {
                continue;
            }
            
            if(map[nx][ny] >= 'A' && map[nx][ny] <= 'F')
            {
                if(!(nkey & (1 << (map[nx][ny] - 'A'))))
                {
                    continue;
                }
            }
            if(map[nx][ny] >= 'a' && map[nx][ny] <= 'f')
            {
                nkey |= (1 << (map[nx][ny] - 'a'));
            }
            if(visited[nx][ny][nkey])
            {
                continue;
            }
            q.push({nx, ny, front.dist + 1, nkey});
            visited[nx][ny][nkey] = 1;
        }
    }
    std::cout << ans << '\n';
    return 0;
}
