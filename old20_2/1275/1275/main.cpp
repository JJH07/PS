//
//  main.cpp
//  1275
//
//  Created by 진준호 on 2020/05/30.
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
    return tree[node] = init(list, tree, node * 2, start, (start + end) / 2) + init(list, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}
ll sum(std::vector<ll> &tree, int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update(std::vector<ll> &tree, int node, int start, int end, int index, ll diff)
{
    if(index < start || end < index)
    {
        return ;
    }
    tree[node] += diff;
    if(start != end)
    {
        update(tree, node * 2, start, (start + end) / 2, index, diff);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, q;
    std::cin >> n >> q;
    std::vector<ll> list(n), tree(1 << ((int)ceil(log2(n)) + 1));
    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i];
    }
    init(list, tree, 1, 0, n - 1);
    for(int i = 0; i < q; i++)
    {
        int x, y, a;
        ll b;
        std::cin >> x >> y >> a >> b;
        if(x > y)
        {
            std::swap(x, y);
        }
        std::cout << sum(tree, 1, 0, n - 1, x - 1, y - 1) << '\n';
        update(tree, 1, 0, n - 1, a - 1, b - list[a - 1]);
        list[a - 1] = b;
    }
    return 0;
}
