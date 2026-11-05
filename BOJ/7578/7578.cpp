//
//  main.cpp
//  7578
//
//  Created by 진준호 on 2020/05/29.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;
void update(std::vector<ll> &tree, int node, int start, int end, int index, ll number)
{
    if(index < start || end < index)
    {
        return ;
    }
    tree[node] += number;
    if(start != end)
    {
        update(tree, node * 2, start, (start + end) / 2, index, number);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, number);
    }
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
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, top[1000001];
    std::cin >> n;
    std::vector<int> list(n);
    std::vector<ll> tree(1 << ((int)ceil(log2(n)) + 1), 0);
    for(int i = 0; i < n; i++)
    {
        int t;
        std::cin >> t;
        top[t] = i;
    }
    for(int i = 0; i < n; i++)
    {
        int t;
        std::cin >> t;
        list[i] = top[t];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        update(tree, 1, 0, n - 1, list[i], 1);
        ans += sum(tree, 1, 0, n - 1, list[i] + 1, n - 1);
    }
    std::cout << ans << '\n';
    return 0;
}
