//
//  main.cpp
//  12100
//
//  Created by 진준호 on 2020/03/07.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

int n, max_v;
std::vector<std::vector<int>> start;
std::vector<std::vector<int>> go(int idx, std::vector<std::vector<int>> map)
{
    std::vector<std::vector<int>> ret = map;
    if(idx == 0)
    {
        for(int i = 0; i < n; i++)
        {
            int bl_idx = 0;
            for(int j = 1; j < n; j++)
            {
                if(ret[i][j] == 0 || j == bl_idx)
                {
                    continue;
                }
                if(ret[i][bl_idx] == 0)
                {
                    ret[i][bl_idx] = ret[i][j];
                    ret[i][j] = 0;
                }
                else if(ret[i][bl_idx] == ret[i][j])
                {
                    ret[i][bl_idx] *= 2;
                    ret[i][j] = 0;
                    bl_idx++;
                }
                else
                {
                    bl_idx++;
                    if(bl_idx != j)
                    {
                        ret[i][bl_idx] = ret[i][j];
                        ret[i][j] = 0;
                    }
                }
            }
        }
    }
    else if(idx == 1)
    {
        for(int j = 0; j < n; j++)
        {
            int bl_idx = 0;
            for(int i = 1; i < n; i++)
            {
                if(ret[i][j] == 0 || i == bl_idx)
                {
                    continue;
                }
                if(ret[bl_idx][j] == 0)
                {
                    ret[bl_idx][j] = ret[i][j];
                    ret[i][j] = 0;
                }
                else if(ret[bl_idx][j] == ret[i][j])
                {
                    ret[bl_idx][j] *= 2;
                    ret[i][j] = 0;
                    bl_idx++;
                }
                else
                {
                    bl_idx++;
                    if(bl_idx != i)
                    {
                        ret[bl_idx][j] = ret[i][j];
                        ret[i][j] = 0;
                    }
                }
            }
        }
    }
    else if(idx == 2)
    {
        for(int i = 0; i < n; i++)
        {
            int bl_idx = n - 1;
            for(int j = n - 2; j >= 0; j--)
            {
                if(ret[i][j] == 0 || j == bl_idx)
                {
                    continue;
                }
                if(ret[i][bl_idx] == 0)
                {
                    ret[i][bl_idx] = ret[i][j];
                    ret[i][j] = 0;
                }
                else if(ret[i][bl_idx] == ret[i][j])
                {
                    ret[i][bl_idx] *= 2;
                    ret[i][j] = 0;
                    bl_idx--;
                }
                else
                {
                    bl_idx--;
                    if(bl_idx != j)
                    {
                        ret[i][bl_idx] = ret[i][j];
                        ret[i][j] = 0;
                    }                }
            }
        }
    }
    else
    {
        for(int j = 0; j < n; j++)
        {
            int bl_idx = n - 1;
            for(int i = n - 2; i >= 0; i--)
            {
                if(ret[i][j] == 0 || i == bl_idx)
                {
                    continue;
                }
                if(ret[bl_idx][j] == 0)
                {
                    ret[bl_idx][j] = ret[i][j];
                    ret[i][j] = 0;
                }
                else if(ret[bl_idx][j] == ret[i][j])
                {
                    ret[bl_idx][j] *= 2;
                    ret[i][j] = 0;
                    bl_idx--;
                }
                else
                {
                    bl_idx--;
                    if(bl_idx != i)
                    {
                        ret[bl_idx][j] = ret[i][j];
                        ret[i][j] = 0;
                    }                }
            }
        }
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::vector<int> tmp;
        for(int j = 0; j < n; j++)
        {
            int t;
            std::cin >> t;
            tmp.push_back(t);
        }
        start.push_back(tmp);
    }

    std::queue<std::vector<int>> q;
    std::vector<int> front;
    for(int i = 0; i < 4; i++)
    {
        q.push({i});
    }
    while(!q.empty())
    {
        front = q.front();
        q.pop();
        int f_sz = (int)front.size();
        if(f_sz < 5)
        {
            front.push_back(0);
            for(int i = 0; i < 4; i++)
            {
                q.push(front);
                front[f_sz]++;
            }
        }
        else
        {
            std::vector<std::vector<int>> ans = start;
            for(auto x : front)
            {
                ans = go(x, ans);
            }
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    max_v = std::max(max_v, ans[i][j]);
                }
            }
        }
    }
    std::cout << max_v << '\n';

    return 0;
}
