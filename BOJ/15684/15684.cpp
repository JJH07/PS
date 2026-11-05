//
//  main.cpp
//  15684
//
//  Created by 진준호 on 2020/03/27.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cstring>

bool conn[31][11], flag;
int n, m, h;
void get_ans(int pick, int x, int y)
{
    if(pick == 0)
    {
        int table[n + 1];
        for(int i = 1; i <= n; i++)
        {
            table[i] = i;
        }
        for(int i = 1; i <= h; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(conn[i][j] == 1)
                {
                    std::swap(table[j], table[j + 1]);
                    j++;
                }
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(table[i] != i)
            {
                return ;
            }
        }
        flag = true;
    }
    if(pick > 0)
    {
        for(int i = x; i <= h; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(i == x && j < y)
                {
                    j = y;
                }
                if(conn[i][j] || conn[i][j - 1] || conn[i][j + 1])
                {
                    continue;
                }
                conn[i][j] = true;
                if(j + 1 == n)
                {
                    get_ans(pick - 1, i + 1, 1);
                }
                else
                {
                    get_ans(pick - 1, i, j + 1);
                }
                conn[i][j] = false;
                if(flag)
                {
                    return;
                }
            }
        }
    }
}
int go()
{
    for(int i = 0; i <= 3; i++)
    {
        get_ans(i, 1, 1);
        if(flag)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m >> h;
    
    for(int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        conn[a][b] = true;
    }
    std::cout << go() << '\n';
    return 0;
}


