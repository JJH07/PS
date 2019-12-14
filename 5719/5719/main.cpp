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
    int v;
    int p;
};
struct comp{
    bool operator()(const road &a, const road &b)
    {
        return a.p > b.p;
    }
};
int n, m, s, d, dist[500];
bool visited[500], prohibited[500][500];
std::vector<int> prior[500];
std::vector<road> list[500];
std::priority_queue<road, std::vector<road>, comp> pq;
void remove_()
{
    std::queue<int> q;
    
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
        dist[i] = INT_MAX;
    }
    
    q.push(d);
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        for(std::vector<int>::iterator it = prior[front].begin(); it != prior[front].end(); it++)
        {
            if(visited[*it])
            {
                continue;
            }
            prohibited[*it][front] = true;
            q.push(*it);
        }
    }
}
int dijkstra()
{
    dist[s] = 0;
    pq.push({s, 0});
    while(!pq.empty())
    {
        road top = pq.top();
        pq.pop();
        if(visited[top.v] || dist[top.v] < top.p)
        {
            continue;
        }
        for(std::vector<road>::iterator it = list[top.v].begin(); it != list[top.v].end(); it++)
        {
            if(visited[it->v] || prohibited[top.v][it->v])
            {
                continue;
            }
            if(dist[it->v] > top.p + it->p)
            {
                dist[it->v] = top.p + it->p;
                prior[it->v].clear();
                prior[it->v].push_back(top.v);
            }
            else if(dist[it->v] == top.p + it->p)
            {
                prior[it->v].push_back(top.v);
            }
            pq.push({it->v, dist[it->v]});
        }
        visited[top.v] = true;
    }
    if(dist[d] == INT_MAX)
    {
        return -1;
    }
    return dist[d];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    while(1)
    {
        std::cin >> n >> m;

        if(n == 0 && m == 0)
        {
            break;
        }
        for(int i = 0; i < n; i++)
        {
            list[i].clear();
            prior[i].clear();
            visited[i] = false;
            for(int j = 0; j < n; j++)
            {
                prohibited[i][j] = false;
            }
            dist[i] = INT_MAX;
        }
        std::cin >> s >> d;
        int u, v, p;
        for(int i = 0; i < m; i++)
        {
            std::cin >> u >> v >> p;
            list[u].push_back({v, p});
        }
        dijkstra();
        remove_();
        std::cout << dijkstra() << '\n';
    }
    return 0;
}
