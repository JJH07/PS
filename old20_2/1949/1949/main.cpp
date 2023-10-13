//
//  main.cpp
//  1949
//
//  Created by 진준호 on 2020/02/10.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>

int n, town[10001], memo[10001][2], visited[10001];
std::vector<int> road[10001];
int go(int state, int idx, int parent)
{
    int &ret = memo[idx][state];
    if(ret != -1)
    {
        return ret;
    }
    ret = state ? town[idx] : 0;
    for(auto it = road[idx].begin(); it != road[idx].end(); it++)
    {
        if(*it == parent)
        {
            continue;
        }
        if(state == 1)
        {
            ret += go(0, *it, idx);
        }
        else
        {
            ret += std::max(go(0, *it, idx), go(1, *it, idx));
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
        std::cin >> town[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        std::cin >> a >> b;
        road[a].push_back(b);
        road[b].push_back(a);
    }
    std::cout << std::max(go(0, 1, 0), go(1, 1, 0)) << '\n';
    return 0;
}
