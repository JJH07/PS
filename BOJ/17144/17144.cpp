//
//  main.cpp
//  17144
//
//  Created by 진준호 on 2020/04/06.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <queue>
int R, C, T, room[51][51];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
struct nd{
    int x;
    int y;
    int dust_spread;
};
void spread()
{
    std::queue<nd> q;
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            if(room[i][j] >= 5)
            {
                q.push({i, j, room[i][j] / 5});
            }
        }
    }
    while(!q.empty())
    {
        nd front = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + front.x;
            int ny = dy[i] + front.y;
            if(nx <= 0 || ny <= 0 || nx > R || ny > C || room[nx][ny] == -1)
            {
                continue;
            }
            room[nx][ny] += front.dust_spread;
            room[front.x][front.y] -= front.dust_spread;
        }
    }
}
void airclean()
{
    int idx = 1;
    for(; idx <= R; idx++)
    {
        if(room[idx][1] == -1)
        {
            break;
        }
    }
    room[idx - 1][1] = 0;
    for(int j = idx - 1; j > 1; j--)
    {
        std::swap(room[j][1], room[j - 1][1]);
    }
    for(int j = 1; j < C; j++)
    {
        std::swap(room[1][j], room[1][j + 1]);
    }
    for(int j = 1; j < idx; j++)
    {
        std::swap(room[j][C], room[j + 1][C]);
    }
    for(int j = C; j > 2; j--)
    {
        std::swap(room[idx][j], room[idx][j - 1]);
    }
    
    idx++;
    
    room[idx + 1][1] = 0;
    for(int j = idx + 1; j < R; j++)
    {
        std::swap(room[j][1], room[j + 1][1]);
    }
    for(int j = 1; j < C;  j++)
    {
        std::swap(room[R][j], room[R][j + 1]);
    }
    for(int j = R; j > idx; j--)
    {
        std::swap(room[j][C], room[j - 1][C]);
    }
    for(int j = C; j > 2; j--)
    {
        std::swap(room[idx][j], room[idx][j - 1]);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> R >> C >> T;
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            std::cin >> room[i][j];
        }
    }
    for(int i = 0; i < T; i++)
    {
        spread();
        airclean();
    }
    int dust = 0;
    for(int i = 1; i <= R; i++)
    {
        for(int j = 1; j <= C; j++)
        {
            if(room[i][j] > 0)
            {
                dust += room[i][j];
            }
        }
    }
    std::cout << dust << '\n';
    return 0;
}
