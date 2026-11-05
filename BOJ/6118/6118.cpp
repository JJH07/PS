//
//  main.cpp
//  6118
//
//  Created by 진준호 on 2020/05/03.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m, visited[20001], distance[20001], max_len = 0;
    std::vector<int> road[20001];
    std::queue<std::pair<int, int>> q;
    
    std::memset(visited, 0, sizeof(visited));
    std::memset(distance, 0, sizeof(distance));
    
    std::cin >> n >> m;
    
    for(int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        road[a].push_back(b);
        road[b].push_back(a);
    }
    
    visited[1] = 1;
    q.push({1, 0});
    while(!q.empty())
    {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        max_len = std::max(max_len, dist);
        for(int next : road[node])
        {
            if(visited[next])
            {
                continue;
            }
            q.push({next, dist + 1});
            visited[next] = 1;
            distance[next] = dist + 1;
        }
    }
    int cnt = 0, node = 20001;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            continue;
        }
        if(distance[i] == max_len)
        {
            node = std::min(node, i);
            cnt++;
        }
    }
    std::cout << node << ' ' << max_len << ' ' << cnt << '\n';
    return 0;
}
