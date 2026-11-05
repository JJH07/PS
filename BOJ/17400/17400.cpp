//
//  main.cpp
//  17400
//
//  Created by 진준호 on 2020/05/11.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

long long init(std::vector<long long> &list, std::vector<long long> &tree, int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = list[start];
    }
    return tree[node] = init(list, tree, node * 2, start, (start + end) / 2) + init(list, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}
long long sum(std::vector<long long> &tree, int node, int start, int end, int left, int right)
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
void update(std::vector<long long> &tree, int node, int start, int end, int index, long long diff)
{
    if(start > index || end < index)
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
long long test()
{
    return -214700000000;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> list, tree(1 << ((int)(ceil(log2(n))) + 1));
    for(int i = 0; i < n; i++)
    {
        long long tmp;
        std::cin >> tmp;
        if(i % 2)
        {
            tmp *= -1;
        }
        list.push_back(tmp);
    }
    init(list, tree, 1, 0, n - 1);
    for(int i = 0; i < q; i++)
    {
        int op;
        std::cin >> op;
        if(op == 1)
        {
            int L, R;
            long long ans;
            std::cin >> L >> R;
            ans = sum(tree, 1, 0, n - 1, L - 1, R - 1);
            if(ans < 0)
            {
                ans *= -1;
            }
            std::cout << ans << '\n';
        }
        else
        {
            int L;
            long long x;
            std::cin >> L >> x;
            if((L - 1) % 2)
            {
                x *= -1;
            }
            update(tree, 1, 0, n - 1, L - 1, x);
            list[L - 1] += x;
        }
    }
    
    return 0;
}
