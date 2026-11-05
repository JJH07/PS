//
//  main.cpp
//  1395
//
//  Created by 진준호 on 2020/06/01.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

int n, m, list[100000], tree[400001], lazy[400001];
void propagate(int node, int start, int end)
{
    if(lazy[node])
    {
        if(start != end)
        {
            lazy[node * 2] = (lazy[node * 2] + 1) % 2;
            lazy[node * 2 + 1] = (lazy[node * 2 + 1] + 1) % 2;
        }
        tree[node] = (end - start + 1) - tree[node];
        lazy[node] = 0;
    }
}
void update(int node, int start, int end, int left, int right)
{
    propagate(node, start, end);
    if(end < left || right < start)
    {
        return ;
    }
    if(left <= start && end <= right)
    {
        lazy[node] = 1;
        propagate(node, start, end);
        return ;
    }
    if(start != end)
    {
        update(node * 2, start, (start + end) / 2, left, right);
        update(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}
int query(int node, int start, int end, int left, int right)
{
    propagate(node, start, end);
    if(end < left || right < start)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return query(node * 2, start, (start + end) / 2, left, right) + query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int o, s, t;
        std::cin >> o >> s >> t;
        if(o)
        {
            std::cout << query(1, 0, n - 1, s - 1, t - 1) << '\n';
        }
        else
        {
            update(1, 0, n - 1, s - 1, t - 1);
        }
    }
    return 0;
}

