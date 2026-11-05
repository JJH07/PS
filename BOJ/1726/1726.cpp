//
//  main.cpp
//  1726
//
//  Created by 진준호 on 2019/11/29.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <queue>

int n, m, map[101][101], visited[101][101][5];
int dx[5][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {1, 2, 3}, {-1, -2, -3}}, dy[5][3] = {{0, 0, 0}, {1, 2, 3}, {-1, -2, -3}, {0, 0, 0}, {0, 0, 0}};
struct node{
    int x;
    int y;
    int dir;
    int dist;
};
node front, end;
std::queue<node> q;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            std::cin >> map[i][j];
        }
    }
    std::cin >> front.x >> front.y >> front.dir;
    std::cin >> end.x >> end.y >> end.dir;
    
    front.dist = 0;
    q.push(front);
    visited[front.x][front.y][front.dir] = 1;
    
    while(!q.empty())
    {
        front = q.front();
        q.pop();
        if(front.x == end.x && front.y == end.y && front.dir == end.dir)
        {
            std::cout << front.dist << '\n';
            break;
        }
        for(int i = 0; i < 3; i++)
        {
            int nx = front.x + dx[front.dir][i];
            int ny = front.y + dy[front.dir][i];
            if(map[nx][ny] == 1)
            {
                break;
            }
            if(nx <= 0 || ny <= 0 || nx > n || ny > m || visited[nx][ny][front.dir] == 1)
            {
                continue;
            }
            visited[nx][ny][front.dir] = 1;
            q.push({nx, ny, front.dir, front.dist + 1});
        }
        if(front.dir <= 2)
        {
            if(visited[front.x][front.y][3] == 0)
            {
                visited[front.x][front.y][3] = 1;
                q.push({front.x, front.y, 3, front.dist + 1});
            }
            if(visited[front.x][front.y][4] == 0)
            {
                visited[front.x][front.y][4] = 1;
                q.push({front.x, front.y, 4, front.dist + 1});
            }
        }
        else
        {
            if(visited[front.x][front.y][1] == 0)
            {
                visited[front.x][front.y][1] = 1;
                q.push({front.x, front.y, 1, front.dist + 1});
            }
            if(visited[front.x][front.y][2] == 0)
            {
                visited[front.x][front.y][2] = 1;
                q.push({front.x, front.y, 2, front.dist + 1});
            }
        }
    }
    return 0;
}
