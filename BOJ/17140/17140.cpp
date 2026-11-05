//
//  main.cpp
//  17140
//
//  Created by 진준호 on 2020/04/10.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

int table[101], A[101][101], rlen = 3, clen = 3;
bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    if(a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}
void R()
{
    int col_max = 0;
    for(int i = 0; i < rlen; i++)
    {
        std::vector<std::pair<int, int>> list;
        std::memset(table, 0, sizeof(table));
        for(int j = 0; j < clen; j++)
        {
            if(A[i][j] > 0)
            {
                table[A[i][j]]++;
            }
        }
        for(int j = 1; j <= 100; j++)
        {
            if(table[j] > 0)
            {
                list.push_back({j, table[j]});
            }
        }
        std::sort(list.begin(), list.end(), cmp);
        int idx = 0;
        for(auto li : list)
        {
            if(idx == 100)
            {
                break;
            }
            A[i][idx++] = li.first;
            A[i][idx++] = li.second;
        }
        for(int j = idx; j < 100; j++)
        {
            A[i][j] = 0;
        }
        col_max = std::max(idx, col_max);
    }
    clen = col_max;
}
void C()
{
    int row_max = 0;
    for(int i = 0; i < clen; i++)
    {
        std::vector<std::pair<int, int>> list;
        std::memset(table, 0, sizeof(table));
        for(int j = 0; j < rlen; j++)
        {
            if(A[j][i] > 0)
            {
                table[A[j][i]]++;
            }
        }
        for(int j = 1; j <= 100; j++)
        {
            if(table[j] > 0)
            {
                list.push_back({j, table[j]});
            }
        }
        std::sort(list.begin(), list.end(), cmp);
        int idx = 0;
        for(auto li : list)
        {
            if(idx == 100)
            {
                break;
            }
            A[idx++][i] = li.first;
            A[idx++][i] = li.second;
        }
        for(int j = idx; j < 100; j++)
        {
            A[j][i] = 0;
        }
        row_max = std::max(idx, row_max);
    }
    rlen = row_max;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int r, c, k, step = 0;
    
    std::cin >> r >> c >> k;
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cin >> A[i][j];
        }
    }
    while(A[r-1][c-1] != k)
    {
        if(step == 100)
        {
            step = -1;
            break;
        }
        step++;
        if(rlen >= clen)
        {
            R();
        }
        else
        {
            C();
        }
    }

    std::cout << step << '\n';
    return 0;
}
