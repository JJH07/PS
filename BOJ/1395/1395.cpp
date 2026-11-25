// Copyright © 2020 진준호. All rights reserved.

#include <iostream>

int n, m, tree[400001], lazy[400001];
void propagate(int node, int start, int end)
{
    if(lazy[node])
    {
        if(start != end)
        {
            lazy[node * 2] ^= 1;
            lazy[node * 2 + 1] ^= 1;
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
        return;
    }
    if(left <= start && end <= right)
    {
        lazy[node] = 1;
        propagate(node, start, end);
        return;
    }
    if(start != end)
    {
        const int mid = (start + end) / 2;
        update(node * 2, start, mid, left, right);
        update(node * 2 + 1, mid + 1, end, left, right);
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
    const int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right)
        + query(node * 2 + 1, mid + 1, end, left, right);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int op, left, right;
        std::cin >> op >> left >> right;
        if(op)
        {
            std::cout << query(1, 0, n - 1, left - 1, right - 1) << '\n';
        }
        else
        {
            update(1, 0, n - 1, left - 1, right - 1);
        }
    }
    return 0;
}
