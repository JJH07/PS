//
//  main.cpp
//  1022
//
//  Created by 진준호 on 2020/01/28.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
int map[51][6], need_space[51][6], r1, c1, r2, c2, x, y, max_len;
int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
bool in_table()
{
    if(x >= 0 && x <= r2 && y >= 0 && y <= c2)
    {
        return true;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...

    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int filled = 1, numbering = 1, cnt = 0, idx = 0;
    
    std::cin >> r1 >> c1 >> r2 >> c2;
    
    r2 -= r1;
    c2 -= c1;
    x -= r1;
    y -= c1;
    r1 = 0;
    c1 = 0;

    if(in_table())
    {
        map[x][y] = numbering;
        filled++;
        max_len = 1;
        need_space[x][y] = 1;
    }
    numbering++;
    while(filled <= (r2 + 1) * (c2 + 1))
    {
        if(idx % 2 == 0)
        {
            cnt++;
        }
        for(int i = 1; i <= cnt; i++)
        {
            x += dx[idx];
            y += dy[idx];
            if(in_table())
            {
                map[x][y] = numbering;
                filled++;
                
                int tmp = numbering, len = 0;
                while(tmp > 0)
                {
                    len++;
                    tmp /= 10;
                }
                need_space[x][y] = len;
                max_len = len;
            }
            numbering++;
        }
        idx = (idx + 1) % 4;
    }
    for(int i = 0; i <= r2; i++)
    {
        for(int j = 0; j <= c2; j++)
        {
            for(int k = 0; k < max_len - need_space[i][j]; k++)
            {
                std::cout << ' ';
            }
            std::cout << map[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
