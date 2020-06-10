//
//  main.cpp
//  15955
//
//  Created by 진준호 on 2020/05/17.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct q_node{
    int from;
    int to;
    int hp;
    int idx;
};
struct pq_node{
    int from;
    int to;
    int diff;
    bool operator <(const pq_node &rhs) const
    {
        return diff > rhs.diff;
    }
};
int parent[250000], ans[250000];
bool query_comp(const q_node &x, const q_node &y)
{
    return x.hp < y.hp;
}
int Find(int n)
{
    if(parent[n] < 0)
    {
        return n;
    }
    return parent[n] = Find(parent[n]);
}
void Union(int x, int y)
{
    int xRoot = Find(x);
    int yRoot = Find(y);
    if(xRoot == yRoot)
    {
        return ;
    }
    parent[xRoot] += parent[yRoot];
    parent[yRoot] = xRoot;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::fill(parent, parent + 250000, -1);
    
    int n, q;
    std::vector<std::pair<int, int>> x, y;
    std::vector<q_node> queries;
    std::priority_queue<pq_node> pq;
    std::cin >> n >> q;
    for(int i = 0; i < n; i++)
    {
        int xi, yi;
        std::cin >> xi >> yi;
        x.push_back({xi, i});
        y.push_back({yi, i});
    }
    for(int i = 0; i < q; i++)
    {
        int ai, bi, xi;
        std::cin >> ai >> bi >> xi;
        queries.push_back({ai - 1, bi - 1, xi, i});
    }
    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end());
    std::sort(queries.begin(), queries.end(), query_comp);
    for(int i = 0; i < n - 1; i++)
    {
        pq.push({x[i].second, x[i + 1].second, x[i + 1].first - x[i].first});
        pq.push({y[i].second, y[i + 1].second, y[i + 1].first - y[i].first});
    }
    for(q_node query : queries)
    {
        while(!pq.empty())
        {
            pq_node top = pq.top();
            if(top.diff > query.hp)
            {
                break;
            }
            pq.pop();
            Union(top.from, top.to);
        }
        if(Find(query.from) == Find(query.to))
        {
            ans[query.idx] = 1;
        }
    }
    for(int i = 0; i < q; i++)
    {
        if(ans[i])
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }
}
