//
//  main.cpp
//  15685
//
//  Created by 진준호 on 2020/03/30.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

int map[101][101], x, y, d, visited[101][101][4][11];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
std::vector<int> list;

void reverse_dragon_curve()
{
    int len = (int)list.size();
    
    for(int i = len - 1; i >= 0; i--)
    {
        int spin_d = (list[i] + 1) % 4;
        x += dx[spin_d];
        y += dy[spin_d];
        list.push_back(spin_d);
        if(x >= 0 && x <= 100 && y >= 0 && y <= 100)
        {
            map[x][y] = 1;
        }
    }
}
void dragon_curve(int g)
{
    if(visited[x][y][d][g] == 1)
    {
        return ;
    }
    visited[x][y][d][g] = 1;
    if(g == 0)
    {
        x += dx[d];
        y += dy[d];
        list.push_back(d);
        if(x >= 0 && x <= 100 && y >= 0 && y <= 100)
        {
            map[x][y] = 1;
        }
    }
    else
    {
        dragon_curve(g - 1);
        reverse_dragon_curve();
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, g;
    
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> x >> y >> d >> g;
        map[x][y] = 1;
        list.clear();
        dragon_curve(g);
    }
    int ans = 0;
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            if((map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]))
            {
                ans++;
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}

