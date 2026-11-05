//
//  main.cpp
//  14890
//
//  Created by 진준호 on 2020/03/21.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cstring>

int n, l, map[101][101], used[101][101], ans;
void dfs1(int x, int y)
{
    if(y == n - 1)
    {
        ans++;
        return ;
    }
    if(map[x][y] == map[x][y + 1])
    {
        dfs1(x, y + 1);
    }
    else if(map[x][y] == map[x][y + 1] + 1)
    {
        for(int i = 2; i <= l; i++)
        {
            if(y + i >= n || map[x][y] != map[x][y + i] + 1)
            {
                return ;
            }
        }
        for(int i = 1; i <= l; i++)
        {
            used[x][y + i] = 1;
        }
        dfs1(x, y + l);
    }
    else if(map[x][y] + 1 == map[x][y + 1])
    {
        for(int i = 0; i < l; i++)
        {
            if(y - i < 0 || used[x][y - i] == 1 || map[x][y - i] + 1 != map[x][y + 1])
            {
                return ;
            }
        }
        for(int i = 0; i < l; i++)
        {
            used[x][y - i] = 1;
        }
        dfs1(x, y + 1);
    }
    else
    {
        return ;
    }
}
void dfs2(int x, int y)
{
    if(x == n - 1)
    {
        ans++;
        return ;
    }
    if(map[x][y] == map[x + 1][y])
    {
        dfs2(x + 1, y);
    }
    else if(map[x][y] == map[x + 1][y] + 1)
    {
        for(int i = 2; i <= l; i++)
        {
            if(x + i >= n || map[x][y] != map[x + i][y] + 1)
            {
                return ;
            }
        }
        for(int i = 1; i <= l; i++)
        {
            used[x + i][y] = 1;
        }
        dfs2(x + l, y);
    }
    else if(map[x][y] + 1 == map[x + 1][y])
    {
        for(int i = 0; i < l; i++)
        {
            if(x - i < 0 || used[x - i][y] == 1 || map[x - i][y] + 1 != map[x + 1][y])
            {
                return ;
            }
        }
        for(int i = 0; i < l; i++)
        {
            used[x - i][y] = 1;
        }
        dfs2(x + 1, y);
    }
    else
    {
        return ;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> l;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        dfs1(i, 0);
    }

    std::memset(used, 0, sizeof(used));
    for(int i = 0; i < n; i++)
    {
        dfs2(0, i);
    }
    std::cout << ans << '\n';
    return 0;
}
