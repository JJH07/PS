//
//  main.cpp
//  1916
//
//  Created by 진준호 on 2020/05/12.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m, distance[1001], s, e;
    std::vector<std::pair<int, int>> plan[1001];
    
    std::fill(distance, distance + 1001, 2147000000);
    
    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        plan[a].push_back({b, c});
    }
    std::cin >> s >> e;
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    
    pq.push({0, s});
    distance[s] = 0;
    while(!pq.empty())
    {
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if(distance[node] > dist)
        {
            continue;
        }
        for(auto next : plan[node])
        {
            int next_node = next.first;
            int next_dist = next.second + dist;
            if(next_dist < distance[next_node])
            {
                distance[next_node] = next_dist;
                pq.push({next_dist, next_node});
            }
        }
    }
    std::cout << distance[e] << '\n';
    return 0;
}
