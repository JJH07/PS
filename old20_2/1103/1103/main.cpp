//
//  main.cpp
//  1103
//
//  Created by 진준호 on 2020/01/29.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>

int n, m, memo[51][51], visited[51][51], checked[51][51];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char map[51][51];
bool flag_loop;

bool dfs(int x, int y)
{
    if(x < 0 || y < 0 || x >= n || y >= m || map[x][y] == 'H')
    {
        return false;
    }
    if(checked[x][y] == 1)
    {
        return false;
    }
    if(visited[x][y] == 1)
    {
        return true;
    }
    visited[x][y] = 1;
    int p = (map[x][y] - '0');
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i] * p;
        int ny = y + dy[i] * p;
        if(dfs(nx, ny))
        {
            return true;
        }
    }
    checked[x][y] = 1;
    visited[x][y] = 0;
    return false;
}
int go(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m || map[x][y] == 'H')
    {
        return 0;
    }
    int &ret = memo[x][y];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    int p = (map[x][y] - '0');
    for(int i = 0; i < 4; i++)
    {
        int nx = x + (dx[i] * p);
        int ny = y + (dy[i] * p);
        ret = std::max(ret, 1 + go(nx, ny));
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::fill(memo[0], memo[0] + 51 * 51, -1);
    
    std::cin >> n >> m;
    
    for(int i = 0; i < n; i++)
    {
        std::cin >> map[i];
    }
    if(dfs(0, 0))
    {
        std::cout << "-1\n";
    }
    else
    {
        std::cout << go(0, 0) << '\n';
    }
    return 0;
}
