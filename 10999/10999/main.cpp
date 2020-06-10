//
//  main.cpp
//  10999
//
//  Created by 진준호 on 2020/04/20.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
long long tree[4000001], lazy[4000001];
std::vector<int> list;
int n, m, k;
long long init(int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = list[start];
    }
    return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}
void propagate(int node, int start, int end)
{
    if(lazy[node])
    {
        if(start != end)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        tree[node] += lazy[node] * (end - start + 1);
        lazy[node] = 0;
    }
}
long long sum(int node, int start, int end, int left, int right)
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
    return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update_(int node, int start, int end, int left, int right, long long add_v)
{
    propagate(node, start, end);
    if(end < left || right < start)
    {
        return ;
    }
    if(left <= start && end <= right)
    {
        lazy[node] = add_v;
        propagate(node, start, end);
        return ;
    }
    update_(node * 2, start, (start + end) / 2, left, right, add_v);
    update_(node * 2 + 1, (start + end) / 2 + 1, end, left, right, add_v);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        std::cin >> tmp;
        list.push_back(tmp);
    }
    init(1, 0, n - 1);
    for(int i = 0; i < m + k; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        if(a == 1)
        {
            long long d;
            std::cin >> d;
            update_(1, 0, n - 1, b - 1, c - 1, d);
        }
        else
        {
            std::cout << sum(1, 0, n - 1, b - 1, c - 1) << '\n';
        }
    }
    return 0;
}
