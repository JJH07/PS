//
//  main.cpp
//  3653
//
//  Created by 진준호 on 2020/05/31.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
void update(std::vector<int> &tree, int node, int start, int end, int index, int diff)
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
int sum(std::vector<int> &tree, int node, int start, int end, int left, int right)
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
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t;
    std::cin >> t;
    while(t--)
    {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> list(n + 1), tree(1 << ((int)ceil(log2(n + m)) + 1), 0);
        for(int i = 1; i <= n; i++)
        {
            list[i] =  n - i + 1;
            update(tree, 1, 1, n + m, list[i], 1);
        }
        for(int i = 1; i <= m; i++)
        {
            int movie;
            std::cin >> movie;
            std::cout << sum(tree, 1, 1, n + m, list[movie] + 1, n + m) << ' ';
            update(tree, 1, 1, n + m, list[movie], -1);
            list[movie] = n + i;
            update(tree, 1, 1, n + m, list[movie], 1);
        }
        std::cout << '\n';
    }
    return 0;
}
