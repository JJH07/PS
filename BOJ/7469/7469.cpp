//
//  main.cpp
//  7469
//
//  Created by 진준호 on 2020/05/26.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
void buildTree(std::vector<int> &list, std::vector<std::vector<int>> &tree, int node, int start, int end)
{
    if(start == end)
    {
        tree[node].push_back(list[start]);
        return ;
    }
    buildTree(list, tree, node * 2, start, (start + end) / 2);
    buildTree(list, tree, node * 2 + 1, (start + end) / 2 + 1, end);
    tree[node].resize(tree[node * 2].size() + tree[node * 2 + 1].size());
    merge(tree[node * 2].begin(), tree[node * 2].end(), tree[node * 2 + 1].begin(), tree[node * 2 + 1].end(), tree[node].begin());
}
int query(std::vector<std::vector<int>> &tree, int node, int start, int end, int left, int right, int number)
{
    if(end < left || right < start)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return upper_bound(tree[node].begin(), tree[node].end(), number) - tree[node].begin();
    }
    return query(tree, node * 2, start, (start + end) / 2, left, right, number) + query(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right, number);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> list(n);
    std::vector<std::vector<int>> tree(1 << ((int)ceil(log2(n)) + 1));
    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i];
    }
    buildTree(list, tree, 1, 0, n - 1);
    for(int i = 0; i < m; i++)
    {
        int from, to, k, l = -1e9, r = 1e9, ans;
        std::cin >> from >> to >> k;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            ans = query(tree, 1, 0, n - 1, from - 1, to - 1, mid);
            if(ans >= k)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        std::cout << l << '\n';
    }
    return 0;
}
