// Copyright © 2020 진준호. All rights reserved.

#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long;

ll build(const std::vector<ll> &values, std::vector<ll> &tree, int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = values[start];
    }
    const int mid = (start + end) / 2;
    return tree[node] = build(values, tree, node * 2, start, mid)
        + build(values, tree, node * 2 + 1, mid + 1, end);
}

ll querySum(const std::vector<ll> &tree, int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    const int mid = (start + end) / 2;
    return querySum(tree, node * 2, start, mid, left, right)
        + querySum(tree, node * 2 + 1, mid + 1, end, left, right);
}

void update(std::vector<ll> &tree, int node, int start, int end, int index, ll diff)
{
    tree[node] += diff;
    if(start == end)
    {
        return;
    }
    const int mid = (start + end) / 2;
    if(index <= mid)
    {
        update(tree, node * 2, start, mid, index, diff);
    }
    else
    {
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    std::vector<ll> values(n), tree(4 * n);
    for(ll &value : values)
    {
        std::cin >> value;
    }
    build(values, tree, 1, 0, n - 1);
    for(int i = 0; i < q; i++)
    {
        int left, right, index;
        ll value;
        std::cin >> left >> right >> index >> value;
        if(left > right)
        {
            std::swap(left, right);
        }
        std::cout << querySum(tree, 1, 0, n - 1, left - 1, right - 1) << '\n';
        update(tree, 1, 0, n - 1, index - 1, value - values[index - 1]);
        values[index - 1] = value;
    }
    return 0;
}
