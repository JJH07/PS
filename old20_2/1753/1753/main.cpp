//
//  main.cpp
//  1753
//
//  Created by 진준호 on 2020/04/27.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int v, e, start, dist[20001], visited[20001];
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    
    std::memset(dist, 0, sizeof(dist));
    std::memset(visited, 0, sizeof(visited));
    
    std::cin >> v >> e >> start;
    
    std::vector<std::pair<int, int>> edge[v + 1];
    
    for(int i = 0; i < e; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        edge[a].push_back({b, c});
    }
    
    pq.push({0, start});
    while(!pq.empty())
    {
        std::pair<int, int> cand = pq.top();
        pq.pop();
        if(visited[cand.second])
        {
            continue;
        }
        visited[cand.second] = 1;
        dist[cand.second] = cand.first;
        for(std::pair<int, int> next : edge[cand.second])
        {
            if(visited[next.first])
            {
                continue;
            }
            pq.push({cand.first + next.second, next.first});
        }
    }
    for(int i = 1; i <= v; i++)
    {
        if(visited[i])
        {
            std::cout << dist[i] << '\n';
        }
        else
        {
            std::cout << "INF\n";
        }
    }
    
    return 0;
}
