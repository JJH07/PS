//
//  main.cpp
//  17143
//
//  Created by 진준호 on 2020/04/06.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cmath>

struct shk{
    int x;
    int y;
    int s;
    int d;
    int z;
    bool valid;
};
int dx[5] = {0, -1, 1, 0, 0}, dy[5] = {0, 0, 0, 1, -1};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int r, c, m, map[101][101], tot_weight = 0;
    shk sharks[10001];
    
    std::memset(map, 0, sizeof(map));
    
    std::cin >> r >> c >> m;
    
    for(int i = 1; i <= m; i++)
    {
        std::cin >> sharks[i].x >> sharks[i].y >> sharks[i].s >> sharks[i].d >> sharks[i].z;
        sharks[i].valid = true;
        map[sharks[i].x][sharks[i].y] = i;
    }
    
    for(int fishing_col = 1; fishing_col <= c; fishing_col++)
    {
        for(int i = 1; i <= r; i++)
        {
            if(map[i][fishing_col] > 0)
            {
                tot_weight += sharks[map[i][fishing_col]].z;
                sharks[map[i][fishing_col]].valid = false;
                break;
            }
        }
        
        std::memset(map, 0, sizeof(map));

        for(int i = 1; i <= m; i++)
        {
            if(!sharks[i].valid)
            {
                continue;
            }
            int nx = sharks[i].x + dx[sharks[i].d] * (sharks[i].s % ((r - 1) * 2));
            int ny = sharks[i].y + dy[sharks[i].d] * (sharks[i].s % ((c - 1) * 2));
            while(nx <= 0 || ny <= 0 || nx > r || ny > c)
            {
                if(sharks[i].d == 1)
                {
                    nx = nx * -1 + 2;
                    sharks[i].d = 2;
                }
                else if(sharks[i].d == 2)
                {
                    nx = r - (nx - r);
                    sharks[i].d = 1;
                }
                else if(sharks[i].d == 3)
                {
                    ny = c - (ny - c);
                    sharks[i].d = 4;
                }
                else
                {
                    ny = ny * -1 + 2;
                    sharks[i].d = 3;
                }
            }
            sharks[i].x = nx;
            sharks[i].y = ny;
            if(map[nx][ny] > 0)
            {
                if(sharks[i].z > sharks[map[nx][ny]].z)
                {
                    sharks[map[nx][ny]].valid = false;
                    map[nx][ny] = i;
                }
                else
                {
                    sharks[i].valid = false;
                }
            }
            else
            {
                map[nx][ny] = i;
            }
        }
    }
    
    std::cout << tot_weight << '\n';
    return 0;
}
