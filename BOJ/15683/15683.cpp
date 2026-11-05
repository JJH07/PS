//
//  main.cpp
//  15683
//
//  Created by 진준호 on 2020/03/25.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

struct nd{
    int x;
    int y;
    int type;
};
int n, m, max_point, rotate_table[8], ans = 21470000;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

std::vector<nd> surveil;
std::vector<std::vector<int>> map, CCTV;
void make_CCTV()
{
    CCTV.push_back({-1});
    CCTV.push_back({1});
    CCTV.push_back({1, 3});
    CCTV.push_back({0, 1});
    CCTV.push_back({0, 1, 3});
    CCTV.push_back({0, 1, 2, 3});
}
void check()
{
    int max_cam = (int)surveil.size();
    std::vector<std::vector<int>> temp = map;
    
    for(int i = 0; i < max_cam; i++)
    {
        int cam_x = surveil[i].x;
        int cam_y = surveil[i].y;
        std::vector<int> origin_r = CCTV[surveil[i].type];
        int rotate_cnt = rotate_table[i];
        for(int idx : origin_r)
        {
            idx = (idx + rotate_cnt) % 4;
            int nx = cam_x;
            int ny = cam_y;
            while(1)
            {
                nx += dx[idx];
                ny += dy[idx];
                if(nx < 0 ||  ny < 0 ||  nx >= n || ny >= m || temp[nx][ny] == 6)
                {
                    break;
                }
                temp[nx][ny] = 7;
            }
        }
    }
    int count = 0;
    for(auto x : temp)
    {
        for(int y : x)
        {
            if(y == 0)
            {
                count++;
            }
        }
    }
    ans = std::min(count, ans);
}
void dfs(int idx)
{
    int max_cam = (int)surveil.size();
    if(idx == max_cam)
    {
        check();
        return ;
    }
    int &type = surveil[idx].type;
    if(type == 5)
    {
        rotate_table[idx] = 0;
        dfs(idx + 1);
    }
    else if(type == 2)
    {
        rotate_table[idx] = 0;
        dfs(idx + 1);
        rotate_table[idx] = 1;
        dfs(idx + 1);
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            rotate_table[idx] = i;
            dfs(idx + 1);
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> m;
    
    map.assign(n, std::vector<int>(m, 0));
    make_CCTV();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cin >> map[i][j];
            if(map[i][j] >= 1 && map[i][j] <= 5)
            {
                surveil.push_back({i, j, map[i][j]});
            }
            if(map[i][j] == 0)
            {
                max_point++;
            }
        }
    }
    dfs(0);
    std::cout << ans << '\n';
    return 0;
}
