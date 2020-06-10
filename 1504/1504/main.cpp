//
//  main.cpp
//  1504
//
//  Created by 진준호 on 2020/05/12.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, e, v1, v2, distance_v1[801], distance_v2[801], distance_1[801];
    std::fill(distance_v1, distance_v1 + 801, 3 * 800 * 1000 + 1);
    std::fill(distance_v2, distance_v2 + 801, 3 * 800 * 1000 + 1);
    std::fill(distance_1, distance_1 + 801, 3 * 800 * 1000 + 1);
    
    std::cin >> n >> e;
    std::vector<std::pair<int, int>> road[801];
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    for(int i = 0; i < e; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        road[a].push_back({b, c});
        road[b].push_back({a, c});
    }
    std::cin >> v1 >> v2;
    
    distance_1[1] = 0;
    pq.push({0, 1});
    while(!pq.empty())
    {
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if(distance_1[node] < dist)
        {
            continue;
        }
        for(auto next : road[node])
        {
            int next_node = next.first;
            int next_dist = next.second + dist;
            if(distance_1[next_node] > next_dist)
            {
                distance_1[next_node] = next_dist;
                pq.push({next_dist, next_node});
            }
        }
    }

    distance_v1[v1] = 0;
    pq.push({0, v1});
    while(!pq.empty())
    {
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if(distance_v1[node] < dist)
        {
            continue;
        }
        for(auto next : road[node])
        {
            int next_node = next.first;
            int next_dist = next.second + dist;
            if(distance_v1[next_node] > next_dist)
            {
                distance_v1[next_node] = next_dist;
                pq.push({next_dist, next_node});
            }
        }
    }
    
    distance_v2[v2] = 0;
    pq.push({0, v2});
    while(!pq.empty())
    {
        int node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if(distance_v2[node] < dist)
        {
            continue;
        }
        for(auto next : road[node])
        {
            int next_node = next.first;
            int next_dist = next.second + dist;
            if(distance_v2[next_node] > next_dist)
            {
                distance_v2[next_node] = next_dist;
                pq.push({next_dist, next_node});
            }
        }
    }
    int ans = std::min(distance_1[v1] + distance_v1[v2] + distance_v2[n], distance_1[v2] + distance_v2[v1] + distance_v1[n]);
    
    std::cout << (ans >= 3 * 800 * 1000 + 1 ? -1 : ans) << '\n';
    return 0;
}
