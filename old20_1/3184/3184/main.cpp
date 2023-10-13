//
//  main.cpp
//  3184
//
//  Created by 진준호 on 2019/12/14.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>

int r, c, visited[250][250], wolf, sheep;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
std::string line[250];

void check(int i, int j)
{
    int sheep_c = 0, wolf_c = 0;
    std::queue<std::pair<int, int>> q;
    
    q.push(std::make_pair(i, j));
    visited[i][j] = 1;
    while(!q.empty())
    {
        std::pair<int, int> front = q.front();
        q.pop();
        switch(line[front.first][front.second])
        {
            case 'o':
                sheep_c++;
                break;
            case 'v':
                wolf_c++;
                break;
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = front.first + dx[i];
            int ny = front.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= r || ny >= c || visited[nx][ny] == 1 || line[nx][ny] == '#')
            {
                continue;
            }
            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }
    if(sheep_c > wolf_c)
    {
        sheep += sheep_c;
    }
    else
    {
        wolf += wolf_c;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> r >> c;
    
    for(int i = 0; i < r; i++)
    {
        std::cin >> line[i];
    }
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(visited[i][j] == 0 && line[i][j] != '#')
            {
                check(i, j);
            }
        }
    }
    std::cout << sheep << ' ' << wolf << '\n';
    return 0;
}
