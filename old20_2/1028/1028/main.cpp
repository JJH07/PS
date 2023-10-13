//
//  main.cpp
//  1028
//
//  Created by 진준호 on 2020/02/17.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>

int r, c, left[751][751], right[751][751], ans = 0;
std::string map[751];
int check_left(int i, int j)
{
    if(map[i][j] == '0' || i < 0 || j < 0 || i >= r || j >= c)
    {
        return 0;
    }
    int &ret = left[i][j];
    if(ret != -1)
    {
        return ret;
    }
    return ret = 1 + check_left(i + 1,  j - 1);
}
int check_right(int i, int j)
{
    if(map[i][j] == '0' || i < 0 || j < 0 || i >= r || j >= c)
    {
        return 0;
    }
    int &ret = right[i][j];
    if(ret != -1)
    {
        return ret;
    }
    return ret = 1 + check_right(i + 1,  j + 1);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    memset(left, -1, sizeof(left));
    memset(right, -1, sizeof(right));
    
    std::cin >> r >> c;
    
    for(int i = 0; i < r; i++)
    {
        std::cin >> map[i];
    }
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(map[i][j] == '1')
            {
                check_left(i, j);
                check_right(i, j);
            }
        }
    }
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(map[i][j] == '1')
            {
                int level = std::min(left[i][j], right[i][j]);
                for(; level > ans; level--)
                {
                    if(right[i + (level - 1)][j - (level - 1)] >= level && left[i + (level - 1)][j + (level - 1)] >= level)
                    {
                        ans = level;
                    }
                }
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}
