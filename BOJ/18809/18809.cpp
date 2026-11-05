//
//  main.cpp
//  18809
//
//  Created by 진준호 on 2020/03/23.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
struct nd{
    int x;
    int y;
    int tick;
};
int n, m, g, r, map[51][51], max_pos, pos_table[11], ans;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
std::vector<std::pair<int, int>> pos;
void get_ans(int max_idx)
{
    int color_map[n][m], time_table[n][m], tick_count = 2, counting = 0;
    std::queue<nd> green, red;
    
    std::memset(color_map, 0, sizeof(color_map));
    std::memset(time_table, 0, sizeof(time_table));
    for(int i = 0; i < max_idx; i++)
    {
        if(pos_table[i] == 0)
        {
            continue;
        }
        else if(pos_table[i] == 1)
        {
            green.push({pos[i].first, pos[i].second, 1});
            color_map[pos[i].first][pos[i].second] = 1;
            time_table[pos[i].first][pos[i].second] = 1;
        }
        else
        {
            red.push({pos[i].first, pos[i].second, 1});
            color_map[pos[i].first][pos[i].second] = 2;
            time_table[pos[i].first][pos[i].second] = 1;
        }
    }
    while(!green.empty() && !red.empty())
    {
        while(!green.empty())
        {
            nd front = green.front();
            if(color_map[front.x][front.y] == -1)
            {
                green.pop();
                continue;
            }
            if(tick_count == front.tick)
            {
                break;
            }
            green.pop();
            for(int i = 0; i < 4; i++)
            {
                int nx = dx[i] + front.x;
                int ny = dy[i] + front.y;
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == 0 || color_map[nx][ny] != 0)
                {
                    continue;
                }
                green.push({nx, ny, front.tick + 1});
                color_map[nx][ny] = 1;
                time_table[nx][ny] = front.tick + 1;
            }
        }
        while(!red.empty())
        {
            nd front = red.front();
            if(color_map[front.x][front.y] == -1)
            {
                red.pop();
                continue;
            }
            if(tick_count == front.tick)
            {
                break;
            }
            red.pop();
            for(int i = 0; i < 4; i++)
            {
                int nx = dx[i] + front.x;
                int ny = dy[i] + front.y;
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == 0 || color_map[nx][ny] == -1 || color_map[nx][ny] == 2)
                {
                    continue;
                }
                if(time_table[nx][ny] == front.tick + 1)
                {
                    counting++;
                    color_map[nx][ny] = -1;
                    continue;
                }
                red.push({nx, ny, front.tick + 1});
                color_map[nx][ny] = 2;
                time_table[nx][ny] = front.tick + 1;
            }
        }
        tick_count++;
    }
    ans = std::max(ans, counting);
}
void permutation_n_go(int idx, int green, int red)
{
    if(green + red == 0)
    {
        get_ans(idx);
        return ;
    }
    if(green + red < max_pos - idx)
    {
        pos_table[idx] = 0;
        permutation_n_go(idx + 1,  green, red);
    }
    if(green > 0)
    {
        pos_table[idx] = 1;
        permutation_n_go(idx + 1, green - 1, red);
    }
    if(red > 0)
    {
        pos_table[idx] = 2;
        permutation_n_go(idx + 1, green, red - 1);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> m >> g >> r;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cin >> map[i][j];
            if(map[i][j] == 2)
            {
                pos.push_back(std::make_pair(i, j));
                max_pos++;
            }
        }
    }
    permutation_n_go(0, g, r);
    std::cout << ans << '\n';
    return 0;
}
