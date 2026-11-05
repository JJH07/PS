//
//  main.cpp
//  2042
//
//  Created by 진준호 on 2020/04/19.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
long long tree_init(std::vector<long long> &list, std::vector<long long> &tree, int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = list[start];
    }
    return tree[node] = tree_init(list, tree, node * 2, start, (start + end) / 2) + tree_init(list, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}
long long tree_sum(std::vector<long long> &tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return tree_sum(tree, node * 2, start, (start + end) / 2, left, right) + tree_sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void tree_update(std::vector<long long> &tree, int node, int start, int end, int index, long long diff)
{
    if(start > index || end < index)
    {
        return ;
    }
    tree[node] += diff;
    if(start != end)
    {
        tree_update(tree, node * 2, start, (start + end) / 2, index, diff);
        tree_update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<long long> list, tree(1 << ((int)(ceil(log2(n))) + 1));
    for(int i = 0; i < n; i++)
    {
        long long tmp;
        std::cin >> tmp;
        list.push_back(tmp);
    }
    tree_init(list, tree, 1, 0, n - 1);
    for(int i = 0; i < m + k; i++)
    {
        int a;
        std::cin >> a;
        if(a == 1)
        {
            int b;
            long long c;
            std::cin >> b >> c;
            tree_update(tree, 1, 0, n - 1, b - 1, c - list[b - 1]);
            list[b - 1] = c;
        }
        else
        {
            int b, c;
            std::cin >> b >> c;
            std::cout << tree_sum(tree, 1, 0, n - 1, b - 1, c - 1) << '\n';
        }
    }
    return 0;
}
