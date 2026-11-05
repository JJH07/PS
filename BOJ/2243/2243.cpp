//
//  main.cpp
//  2243
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
int query(std::vector<int> &tree, int node, int start, int end, int b)
{
    if(start == end)
    {
        return start;
    }
    if(b <= tree[node * 2])
    {
        return query(tree, node * 2, start, (start + end) / 2, b);
    }
    else
    {
        return query(tree, node * 2 + 1, (start + end) / 2 + 1, end, b - tree[node * 2]);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::vector<int> list(1000001, 0), tree(1 << ((int)ceil(log2(1000001)) + 1));
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        if(a == 1)
        {
            int ans = query(tree, 1, 1, 1000000, b);
            std::cout << ans << '\n';
            update(tree, 1, 1, 1000000, ans, -1);
            list[ans]--;
        }
        else
        {
            int c;
            std::cin >> c;
            if(list[b] + c < 0)
            {
                continue;
            }
            update(tree, 1, 1, 1000000, b, c);
            list[b] += c;
        }
    }
    
    return 0;
}
