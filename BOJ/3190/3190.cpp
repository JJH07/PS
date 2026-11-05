//
//  main.cpp
//  3190
//
//  Created by 진준호 on 2020/03/16.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
#include <deque>
struct pos
{
    int x;
    int y;
};
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, k, l, apple[101][101], visited[101][101];
    char drift[10001];
    
    std::memset(apple, 0, sizeof(apple));
    std::memset(visited, 0, sizeof(visited));
    std::memset(drift, 0, sizeof(drift));
    
    std::cin >> n >> k;
    for(int i = 0; i < k; i++)
    {
        int x, y;
        std::cin >> x >> y;
        apple[x][y] = 1;
    }
    std::cin >> l;
    for(int i = 0; i < l; i++)
    {
        int x;
        char c;
        std::cin >> x >> c;
        drift[x] = c;
    }
    
    std::deque<pos> snake;
    int tick = 0, way = 0;
    pos p = {1, 1};
    visited[1][1] = 1;
    snake.push_back(p);
    while(1)
    {
        pos head = snake.front();
        pos tail = snake.back();
        
        tick++;
        
        int nx = head.x + dx[way];
        int ny = head.y + dy[way];
        if(nx < 1 || ny < 1 || nx > n || ny > n || visited[nx][ny])
        {
            break;
        }
        snake.push_front({nx, ny});
        visited[nx][ny] = 1;
        if(apple[nx][ny])
        {
            apple[nx][ny] = 0;
        }
        else
        {
            snake.pop_back();
            visited[tail.x][tail.y] = 0;
        }
        if(drift[tick] == 'D')
        {
            way = (way + 1) % 4;
        }
        if(drift[tick] == 'L')
        {
            way = (way + 3) % 4;
        }
    }
    std::cout << tick << '\n';
    return 0;
}
