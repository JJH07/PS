//
//  main.cpp
//  17779
//
//  Created by 진준호 on 2020/04/11.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cstring>

int n, section[21][21], ans = 21470000;
void get_ans(int x, int y, int d1, int d2)
{
    int map[n + 1][n + 1], max_ = 0, min_ = 21470000, sum;
    
    std::memset(map, 0, sizeof(map));
    
    for(int i = 0; i <= d1; i++)
    {
        map[x + i][y - i] = 5;
        map[x + d2 + i][y + d2 - i] = 5;
    }
    for(int i = 0; i <= d2; i++)
    {
        map[x + i][y + i] = 5;
        map[x + d1 + i][y - d1 + i] = 5;
    }

    for(int i = 1; i <= n; i++)
    {
        int start = 0, end = 0;
        for(int j = 1; j <= n; j++)
        {
            if(map[i][j] == 5)
            {
                start = j;
                break;
            }
        }
        for(int j = n; j >= 1; j--)
        {
            if(map[i][j] == 5)
            {
                end = j;
                break;
            }
        }
        for(int j = start + 1; j < end; j++)
        {
            map[i][j] = 5;
        }
    }
    
    sum = 0;
    for(int i = 1; i < x + d1; i++)
    {
        for(int j = 1; j <= y; j++)
        {
            if(map[i][j] > 0)
            {
                break;
            }
            map[i][j] = 1;
            sum += section[i][j];
        }
    }
    max_ = std::max(max_, sum);
    min_ = std::min(min_, sum);
    
    sum = 0;
    for(int i = 1; i <= x + d2; i++)
    {
        for(int j = y + 1; j <= n; j++)
        {
            if(map[i][j] > 0)
            {
                continue;
            }
            map[i][j] = 2;
            sum += section[i][j];
        }
    }
    max_ = std::max(max_, sum);
    min_ = std::min(min_, sum);
    
    sum = 0;
    for(int i = x + d1; i <= n; i++)
    {
        for(int j = 1; j < y - d1 + d2; j++)
        {
            if(map[i][j] > 0)
            {
                break;
            }
            map[i][j] = 3;
            sum += section[i][j];
        }
    }
    max_ = std::max(max_, sum);
    min_ = std::min(min_, sum);
    
    sum = 0;
    for(int i = x + d2 + 1; i <= n; i++)
    {
        for(int j = y - d1 + d2; j <= n; j++)
        {
            if(map[i][j] > 0)
            {
                continue;
            }
            map[i][j] = 4;
            sum += section[i][j];
        }
    }
    max_ = std::max(max_, sum);
    min_ = std::min(min_, sum);
    
    sum = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(map[i][j] == 5)
            {
                sum += section[i][j];
            }
        }
    }
    max_ = std::max(max_, sum);
    min_ = std::min(min_, sum);

    ans = std::min(ans, max_ - min_);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cin >> section[i][j];
        }
    }

    for(int d1 = 1; d1 <= n; d1++)
    {
        for(int d2 = 1; d2 <= n; d2++)
        {
            for(int x = 1; x <= n; x++)
            {
                if(x + d1 + d2 > n)
                {
                    break;
                }
                for(int y = 1; y <= n; y++)
                {
                    if(y - d1 >= 1 && y + d2 <= n)
                    {
                        get_ans(x, y, d1, d2);
                    }
                }
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}
