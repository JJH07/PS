//
//  main.cpp
//  5719
//
//  Created by 진준호 on 2019/12/04.
//  Copyright © 2019 진준호. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <climits>

struct road{
    int u;
    int v;
    int p;
};
struct dist{
    int distance;
    std::vector<int> before;
};
struct comp{
    bool operator()(const road &a, const road &b)
    {
        return a.p > b.p;
    }
};

int dijkstra(int s, int d, std::vector<std::vector<std::pair<int, int>>> &list)
{
    std::priority_queue<road, std::vector<road>, comp> pq;
    
    int visited[501][501];
    dist dists[501];
    
    std::fill(visited[0], visited[0] + 501 * 501, 0);
    for(int i = 0; i < 501; i++)
    {
        dists[i].distance = INT_MAX;
        dists[i].before = {-1};
    }
    
    dists[s].distance = 0;
    for(std::vector<std::pair<int, int>>::iterator it = list[s].begin(); it != list[s].end(); it++)
    {
        pq.push({s, it->first, it->second});
        visited[s][it->first] = 1;
    }
    while(!pq.empty())
    {
        road top = pq.top();
        pq.pop();
        if(visited[top.u][top.v] == 1)
        {
            continue;
        }
        int new_dist = dists[top.u].distance + top.p;
        if(dists[top.v].distance > new_dist)
        {
            dists[top.v].distance = new_dist;
            dists[top.v].before.clear();
            dists[top.v].before.push_back(top.u);
        }
        else if(dists[top.v].distance == new_dist)
        {
            dists[top.v].before.push_back(top.u);
        }
        visited[top.u][top.v] = 1;
        for(std::vector<std::pair<int, int>>::iterator it = list[top.v].begin(); it != list[top.v].end(); it++)
        {
            if(visited[top.v][it->first] == 0)
            {
                pq.push({top.v, it->first, it->second});
                visited[s][it->first] = 1;
            }
        }
    }
    std::cout << dists[d].distance << "!!\n";
    for(int i = 0; i < (int)dists[d].before.size(); i++)
    {
        std::cout << dists[d].before[i] << '\n';
    }
    return 0;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m, s, d;

    std::vector<std::vector<std::pair<int, int>>> list;
    list.reserve(501);
    
    while(1)
    {
        std::cin >> n >> m;

        if(n == 0 && m == 0)
        {
            break;
        }
        std::cin >> s >> d;
        int u, v, p;
        for(int i = 0; i < m; i++)
        {
            std::cin >> u >> v >> p;
            list[u].push_back(std::make_pair(v, p));
        }

        std::cout << dijkstra(s, d, list) << '\n';
        
        for(int i = 0; i < n; i++)
        {
            list[i].clear();
        }
    }
    
    
    return 0;
}
