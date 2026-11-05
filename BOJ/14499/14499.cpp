//
//  main.cpp
//  14499
//
//  Created by 진준호 on 2020/03/16.
//  Copyright © 2020 진준호. All rights reserved.
//
#include <cstring>
#include <iostream>

int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m, x, y, k, map[21][21];
    int pages[6];
    std::memset(pages, 0, sizeof(pages));
    
    std::cin >> n >> m >> x >> y >> k;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cin >> map[i][j];
        }
    }
    for(int i = 0; i < k; i++)
    {
        int way;
        std::cin >> way;
        way--;
        int nx = x + dx[way];
        int ny = y + dy[way];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m)
        {
            continue;
        }
        x = nx;
        y = ny;
        if(way == 0)
        {
            std::swap(pages[5], pages[2]);
            std::swap(pages[3], pages[2]);
            std::swap(pages[2], pages[0]);
        }
        else if(way == 1)
        {
            std::swap(pages[5], pages[3]);
            std::swap(pages[3], pages[0]);
            std::swap(pages[2], pages[0]);
        }
        else if(way == 2)
        {
            std::swap(pages[1], pages[0]);
            std::swap(pages[0], pages[4]);
            std::swap(pages[4], pages[5]);
        }
        else
        {
            std::swap(pages[5], pages[4]);
            std::swap(pages[4], pages[0]);
            std::swap(pages[0], pages[1]);
        }
        if(map[x][y] == 0)
        {
            map[x][y] = pages[5];
        }
        else
        {
            pages[5] = map[x][y];
            map[x][y] = 0;
        }
        std::cout << pages[0] << '\n';
    }
    return 0;
}
