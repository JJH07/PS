//
//  main.cpp
//  16235
//
//  Created by 진준호 on 2020/04/04.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <deque>
#include <algorithm>
struct tree{
    int x;
    int y;
    int old;
};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m, k, A[11][11], soil[11][11], dead_tree;
    std::deque<int> living_tree[11][11];
    
    std::cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cin >> A[i][j];
            soil[i][j] = 5;
        }
    }
    for(int i = 0; i < m; i++)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        living_tree[x][y].push_back(z);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if((int)living_tree[i][j].size() > 1)
            {
                std::sort(living_tree[i][j].begin(), living_tree[i][j].end());
            }
        }
    }
    
    
    for(int year = 0; year < k; year++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dead_tree = 0;
                for(std::deque<int>::iterator it = living_tree[i][j].begin(); it < living_tree[i][j].end();)
                {
                    if(soil[i][j] >= *it)
                    {
                        soil[i][j] -= *it;
                        *it += 1;
                        it++;
                    }
                    else
                    {
                        dead_tree += (*it / 2);
                        it = living_tree[i][j].erase(it);
                    }
                }
                soil[i][j] += dead_tree;
            }
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                for(int x : living_tree[i][j])
                {
                    if((x % 5) == 0)
                    {
                        for(int idx = 0; idx < 8; idx++)
                        {
                            int nx = dx[idx] + i;
                            int ny = dy[idx] + j;
                            if(nx <= 0 || ny <= 0 || nx > n || ny > n)
                            {
                                continue;
                            }
                            living_tree[nx][ny].push_front(1);
                        }
                    }
                }
                soil[i][j] += A[i][j];
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            ans += (int)living_tree[i][j].size();
        }
    }
    std::cout << ans << '\n';
    return 0;
}
