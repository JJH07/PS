//
//  main.cpp
//  5676
//
//  Created by 진준호 on 2020/06/04.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

int init(std::vector<int> &list, std::vector<int> &tree, int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = list[start];
    }
    return tree[node] = init(list, tree, node * 2, start, (start + end) / 2) * init(list, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}
int multiply(std::vector<int> &tree, int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return 1;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return multiply(tree, node * 2, start, (start + end) / 2, left, right) * multiply(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int update(std::vector<int> &tree, int node, int start, int end, int index, int change)
{
    if(index < start || end < index)
    {
        return tree[node];
    }
    if(start == end)
    {
        return tree[node] = change;
    }
    return tree[node] = update(tree, node * 2, start, (start + end) / 2, index, change) * update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, change);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, k;
    while(!(std::cin >> n >> k).eof())
    {
        std::vector<int> list(n), tree(1 << ((int)ceil(log2(n)) + 1));
        for(int i = 0; i < n; i++)
        {
            std::cin >> list[i];
            list[i] = list[i] > 0 ? 1 : (list[i] < 0 ? -1 : 0);
        }
        init(list, tree, 1, 0, n - 1);
        char op;
        int x, y;
        for(int i = 0; i < k; i++)
        {
            std::cin >> op >> x >> y;
            if(op == 'C')
            {
                y = y > 0 ? 1 : (y < 0 ? -1 : 0);
                list[x - 1] = y;
                update(tree, 1, 0, n - 1, x - 1, y);
            }
            else
            {
                int ans = multiply(tree, 1, 0, n - 1, x - 1, y - 1);
                char ret = ans > 0 ? '+' : (ans < 0 ? '-' : '0');
                std::cout << ret;
            }
        }
        std::cout << '\n';
    }
    return 0;
}
