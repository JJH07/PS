//
//  main.cpp
//  1043
//
//  Created by 진준호 on 2020/02/18.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>

int n, m, t, t_mem[50], p, tmp, truth[51];
std::vector<int> group[51], member[51];

void tell_truth(int mem_idx)
{
    for(auto g_it = member[mem_idx].begin(); g_it != member[mem_idx].end(); g_it++)
    {
        if(truth[*g_it] == 0)
        {
            truth[*g_it] = 1;
            for(auto m_it = group[*g_it].begin(); m_it != group[*g_it].end(); m_it++)
            {
                tell_truth(*m_it);
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> m >> t;
    for(int i = 0; i < t; i++)
    {
        std::cin >> t_mem[i];
    }
    for(int i = 1; i <= m; i++)
    {
        std::cin >> p;
        for(int j = 0; j < p; j++)
        {
            std::cin >> tmp;
            group[i].push_back(tmp);
            member[tmp].push_back(i);
        }
    }
    for(int i = 0; i < t; i++)
    {
        tell_truth(t_mem[i]);
    }
    int ans = 0;
    for(int i = 1; i <= m; i++)
    {
        if(truth[i] == 0)
        {
            ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}
