//
//  main.cpp
//  1613
//
//  Created by 진준호 on 2019/11/29.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

int n, k, s, visited[401];
std::vector<int> list[401];

int historic(int a, int b)
{
    std::queue<int> q;
    int front;
    
    std::fill(visited, visited + 401, 0);
    q.push(a);
    visited[a] = 1;
    while(!q.empty())
    {
        front = q.front();
        q.pop();
        if(front == b)
        {
            return -1;
        }
        int list_len = (int)list[front].size();
        for(int i = 0; i < list_len; i++)
        {
            if(visited[list[front][i]] == 0)
            {
                q.push(list[front][i]);
                visited[list[front][i]] = 1;
            }
        }
    }
    
    visited[a] = 0;
    q.push(b);
    visited[b] = 1;
    while(!q.empty())
    {
        front = q.front();
        q.pop();
        if(front == a)
        {
            return 1;
        }
        int list_len = (int)list[front].size();
        for(int i = 0; i < list_len; i++)
        {
            if(visited[list[front][i]] == 0)
            {
                q.push(list[front][i]);
                visited[list[front][i]] = 1;
            }
        }
    }
    
    return 0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin.tie(NULL);
    std::cin.sync_with_stdio(false);
    
    int a, b;
    
    std::cin >> n >> k;
    for(int i = 0; i < k; i++)
    {
        std::cin >> a >> b;
        list[a].push_back(b);
    }
    std::cin >> s;
    for(int i = 0 ; i < s; i++)
    {
        std::cin >> a >> b;
        std::cout << historic(a, b) << '\n';
    }
    return 0;
}
