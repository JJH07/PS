//
//  main.cpp
//  2357
//
//  Created by 진준호 on 2020/04/19.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
int init_max(std::vector<int> &list, std::vector<int> &tree, int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = list[start];
    }
    return tree[node] = std::max(init_max(list, tree, node * 2, start, (start + end) / 2), init_max(list, tree, node * 2 + 1, (start + end) / 2 + 1, end));
}
int init_min(std::vector<int> &list, std::vector<int> &tree, int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = list[start];
    }
    return tree[node] = std::min(init_min(list, tree, node * 2, start, (start + end) / 2), init_min(list, tree, node * 2 + 1, (start + end) / 2 + 1, end));
}

int maxim(std::vector<int> &tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start)
    {
        return INT_MIN;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return std::max(maxim(tree, node * 2, start, (start + end) / 2, left, right), maxim(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int minim(std::vector<int> &tree, int node, int start, int end, int left, int right)
{
    if(left > end || right < start)
    {
        return INT_MAX;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return std::min(minim(tree, node * 2, start, (start + end) / 2, left, right), minim(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m;
    std::cin >> n >> m;
    std::vector<int> list, tree_min(1 << ((int)ceil(log2(n)) + 1)), tree_max(1 << ((int)ceil(log2(n)) + 1));
    for(int i = 0; i < n; i++)
    {
        int tmp;
        std::cin >> tmp;
        list.push_back(tmp);
    }
    init_max(list, tree_max, 1, 0, n - 1);
    init_min(list, tree_min, 1, 0, n - 1);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        std::cout << minim(tree_min, 1, 0, n - 1, a - 1, b - 1) << ' ' << maxim(tree_max, 1, 0, n - 1, a - 1, b - 1) << '\n';
    }
    
    return 0;
}
