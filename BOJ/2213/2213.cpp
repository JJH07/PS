//
//  main.cpp
//  2213
//
//  Created by 진준호 on 2020/01/31.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

int n, w[10001], memo[10001][2];
std::vector<int> con[10001], list;
void trace(int before, int now, bool state)
{
    if(state == 1)
    {
        for(std::vector<int>::iterator it = con[now].begin(); it != con[now].end(); it++)
        {
            if(before == *it)
            {
                continue;
            }
            trace(now, *it, false);
        }
        return ;
    }
    bool flag = false;
    if(memo[now][0] <= memo[now][1])
    {
        list.push_back(now);
        flag = true;
    }
    for(std::vector<int>::iterator it = con[now].begin(); it != con[now].end(); it++)
    {
        if(before == *it)
        {
            continue;
        }
        trace(now, *it, flag);
    }
}
int go(int before, int now, int state)
{
    if(before > 0 && (int)con[now].size() == 1)
    {
        return state ? w[now] : 0;
    }
    int &ret = memo[now][state];
    if(ret != -1)
    {
        return ret;
    }
    if(state == 1)
    {
        ret = w[now];
    }
    else
    {
        ret = 0;
    }
    for(std::vector<int>::iterator it = con[now].begin(); it != con[now].end(); it++)
    {
        if(before == *it)
        {
            continue;
        }
        if(state == 0)
        {
            ret += std::max(go(now, *it, 0), go(now, *it, 1));
        }
        else
        {
            ret += go(now, *it, 0);
        }
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::fill(memo[0], memo[0] + 10001 * 2, -1);
    
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> w[i];
    }
    int s, e;
    for(int i = 0; i < n - 1; i++)
    {
        std::cin >> s >> e;
        con[s].push_back(e);
        con[e].push_back(s);
    }
    std::cout << std::max(go(0, 1, 0), go(0, 1, 1)) << '\n';
    trace(0, 1, 0);
    std::sort(list.begin(), list.end());
    for(std::vector<int>::iterator it = list.begin(); it != list.end(); it++)
    {
        std::cout << *it << ' ';
    }
    return 0;
}
