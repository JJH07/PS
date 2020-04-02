//
//  main.cpp
//  18808
//
//  Created by 진준호 on 2020/03/23.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
void rotate(std::vector<std::vector<int>> &sticker)
{
    int r = (int)sticker.size();
    int c = (int)sticker[0].size();
    std::vector<std::vector<int>> tmp(c, std::vector<int>(r, 0));
    for(int i = 0; i < c; i++)
    {
        for(int j = 0; j < r; j++)
        {
            tmp[i][j] = sticker[r - 1 - j][i];
        }
    }
    sticker = tmp;
}
bool check(std::vector<std::vector<int>> &map, std::vector<std::vector<int>> &sticker)
{
    int map_x = (int)map.size();
    int map_y = (int)map[0].size();
    int sticker_x = (int)sticker.size();
    int sticker_y = (int)sticker[0].size();
    for(int i = 0; i <= map_x - sticker_x; i++)
    {
        for(int j = 0; j <= map_y - sticker_y; j++)
        {
            bool FLAG_NO = false;
            for(int x = 0; x < sticker_x; x++)
            {
                for(int y = 0; y < sticker_y; y++)
                {
                    if(sticker[x][y] == 1 && map[i + x][j + y] == 1)
                    {
                        FLAG_NO = true;
                        break;
                    }
                }
                if(FLAG_NO)
                {
                    break;
                }
            }
            if(!FLAG_NO)
            {
                for(int x = 0; x < sticker_x; x++)
                {
                    for(int y = 0; y < sticker_y; y++)
                    {
                        if(sticker[x][y] == 1)
                        {
                            map[i + x][j + y] = 1;
                        }
                    }
                }
                return true;
            }
        }
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m, k;
    
    std::cin >> n >> m >> k;
    
    std::vector<std::vector<int>> notebook(n, std::vector<int>(m, 0));
    
    for(int i = 0; i < k; i++)
    {
        int r, c;
        std::cin >> r >> c;
        std::vector<std::vector<int>> sticker(r, std::vector<int>(c, 0));
        for(int x = 0; x < r; x++)
        {
            for(int y = 0; y < c; y++)
            {
                std::cin >> sticker[x][y];
            }
        }
        for(int p = 0; p < 4; p++)
        {
            if(check(notebook, sticker))
            {
                break;
            }
//            for(auto x : sticker)
//            {
//                for(auto y : x)
//                {
//                    std::cout << y << ' ';
//                }
//                std::cout << '\n';
//            }
//            std::cout << '\n';
            rotate(sticker);
        }
    }
    int cnt = 0;
    for(auto x : notebook)
    {
        for(auto y : x)
        {
            if(y == 1)
            {
                cnt++;
            }
        }
    }
    std::cout << cnt << '\n';
    return 0;
}
