//
//  main.cpp
//  2268
//
//  Created by 진준호 on 2020/06/04.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;
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
    
    int n, k;
    std::cin >> n >> k;
    std::vector<ll> list(n + 1, 0), tree(1 << ((int)ceil(log2(n)) + 1), 0);
    for(int i = 0; i < k; i++)
    {
        int op, first;
        std::cin >> op >> first;
        if(op == 0)
        {
            int second;
            std::cin >> second;
            if(first > second)
            {
                std::swap(first, second);
            }
            std::cout << sum(tree, 1, 0, n - 1, first - 1, second - 1) << '\n';
        }
        else
        {
            ll second;
            std::cin >> second;
            update(tree, 1, 0, n - 1, first - 1, second - list[first - 1]);
            list[first - 1] = second;
        }
    }
    return 0;
}
