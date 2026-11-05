//
//  main.cpp
//  2211
//
//  Created by 진준호 on 2020/05/15.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

struct node{
    int from;
    int to;
    int time;
};
bool operator <(const node& a, const node& b)
{
    return std::tie(a.time, a.from, a.to) > std::tie(b.time, b.from, b.to);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::pair<int, int>> link[n + 1], list;
    int initial_network[n + 1];
    std::priority_queue<node> pq;

    std::fill(initial_network, initial_network + n + 1, (n + 1) * 10);

    for(int i = 0; i < m; i++)
    {
        int A, B, C;
        std::cin >> A >> B >> C;
        link[A].push_back({B, C});
        link[B].push_back({A, C});
    }

    initial_network[1] = 0;
    pq.push({0, 1, 0});
    while(!pq.empty())
    {
        node top = pq.top();
        pq.pop();
        int from = top.from;
        int to = top.to;
        int dist = top.time;
        if(initial_network[to] < dist)
        {
            continue;
        }
        if(from > 0)
        {
            list.push_back({from, to});
        }
        for(auto next : link[to])
        {
            int next_node = next.first;
            int next_dist = next.second + dist;
            if(initial_network[next_node] > next_dist)
            {
                initial_network[next_node] = next_dist;
                pq.push({to, next_node, next_dist});
            }
        }
    }
    std::cout << list.size() << '\n';
    for(auto x : list)
    {
        std::cout << x.first << ' ' << x.second << '\n';
    }
    return 0;
}
