//
//  main.cpp
//  17396
//
//  Created by 진준호 on 2020/05/09.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m;
    std::cin >> n >> m;
    std::vector<int> visible(n);
    std::vector<long long> distance(n, 1000000000000);
    std::vector<std::pair<int, long long>> road[n];
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
    
    for(int i = 0; i < n; i++)
    {
        std::cin >> visible[i];
    }
    visible[n - 1] = 0;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        long long t;
        std::cin >> a >> b >> t;
        if(visible[a] || visible[b])
        {
            continue;
        }
        road[a].push_back({b, t});
        road[b].push_back({a, t});
    }
    
    pq.push({0, 0});
    distance[0] = 0;
    while(!pq.empty())
    {
        int node = pq.top().second;
        long long dist = pq.top().first;
        pq.pop();
        if(distance[node] < dist)
        {
            continue;
        }
        for(auto next : road[node])
        {
            int nd = next.first;
            long long nd_dist = dist + next.second;
            if(distance[nd] > nd_dist)
            {
                distance[nd] = nd_dist;
                pq.push({nd_dist, nd});
            }
        }
    }
    if(distance[n - 1] == 1000000000000)
    {
        distance[n - 1] = -1;
    }
    std::cout << distance[n - 1]  << '\n';
    return 0;
}
