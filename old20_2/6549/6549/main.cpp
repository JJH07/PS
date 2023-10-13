//
//  main.cpp
//  6549
//
//  Created by 진준호 on 2020/05/26.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <vector>
typedef long long ll;
int init(std::vector<ll> &list, std::vector<int> &tree, int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = start;
    }
    int left = init(list, tree, node * 2, start, (start + end) / 2);
    int right = init(list, tree, node * 2 + 1, (start + end) / 2 + 1, end);
    return tree[node] = list[left] > list[right] ? right : left;
}
int query(std::vector<ll> &list, std::vector<int> &tree, int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return -1;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    int left_v = query(list, tree, node * 2, start, (start + end) / 2, left, right);
    int right_v = query(list, tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    if(left_v == -1)
    {
        return right_v;
    }
    if(right_v == -1)
    {
        return left_v;
    }
    return list[left_v] > list[right_v] ? right_v : left_v;
}
ll get_ans(std::vector<ll> &list, std::vector<int> &tree, int start, int end, int left, int right)
{
    int k = query(list, tree, 1, start, end, left, right);
    ll ans = list[k] * (right - left + 1);
    if(left < k)
    {
        ans = std::max(ans, get_ans(list, tree, start, end, left, k - 1));
    }
    if(right > k)
    {
        ans = std::max(ans, get_ans(list, tree, start, end, k + 1, right));
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::vector<int> tree(400001);
    while(1)
    {
        int n;
        std::cin >> n;
        if(n == 0)
        {
            break;
        }
        std::vector<ll> list(n);
        for(int i = 0; i < n; i++)
        {
            std::cin >> list[i];
        }
        init(list, tree, 1, 0, n - 1);
        ll ans = get_ans(list, tree, 0, n - 1, 0, n - 1);
        std::cout << ans << '\n';
    }
    
    return 0;
}
