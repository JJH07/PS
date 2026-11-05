//
//  main.cpp
//  11505
//
//  Created by 진준호 on 2020/05/29.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;

ll init(std::vector<ll> &list, std::vector<ll> &tree, int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = list[start];
    }
    return tree[node] = (init(list, tree, node * 2, start, (start + end) / 2) * init(list, tree, node * 2 + 1, (start + end) / 2 + 1, end)) % 1000000007;
}
ll multiply(std::vector<ll> &tree, int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return 1;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return (multiply(tree, node * 2, start, (start + end) / 2, left, right) * multiply(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right)) % 1000000007;
}
ll update(std::vector<ll> &tree, int node, int start, int end, int index, ll change)
{
    if(index < start || end < index)
    {
        return tree[node];
    }
    if(start == end)
    {
        return tree[node] = change;
    }
    return tree[node] = (update(tree, node * 2, start, (start + end) / 2, index, change) * update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, change)) % 1000000007;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<ll> list(n), tree(1 << ((int)ceil(log2(n)) + 1));
    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i];
    }
    init(list, tree, 1, 0, n - 1);
    for(int i = 0; i < m + k; i++)
    {
        int a, b;
        std::cin >> a >> b;
        if(a == 1)
        {
            ll c;
            std::cin >> c;
            update(tree, 1, 0, n - 1, b - 1, c);
            list[b - 1] = c;
        }
        else
        {
            int c;
            std::cin >> c;
            std::cout << multiply(tree, 1, 0, n - 1, b - 1, c - 1) << '\n';
        }
    }
    return 0;
}
