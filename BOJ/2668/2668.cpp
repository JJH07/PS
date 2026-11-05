//
//  main.cpp
//  2668
//
//  Created by 진준호 on 2019/12/25.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <stack>
#include <algorithm>

int n, list[101];
bool visited[101];
int dfs(int start)
{
    std::stack<int> stk;
    stk.push(start);
    visited[start] = true;
    while(1)
    {
        int top = stk.top();
        if(visited[list[top]])
        {
            break;
        }
        stk.push(list[top]);
        visited[list[top]] = true;
    }
    if(start != list[stk.top()])
    {
        while(!stk.empty())
        {
            int top = stk.top();
            visited[top] = false;
            stk.pop();
        }
    }
    return (int)stk.size();
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int cnt = 0;
    
    std::cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        std::cin >> list[i];
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == false)
        {
            cnt += dfs(i);
        }
    }
    std::cout << cnt << '\n';
    for(int i = 1; i <= n; i++)
    {
        if(visited[i])
        {
            std::cout << i << '\n';
        }
    }
    return 0;
}
