#include <iostream>
#include <vector>
#define MAX 100000

int n, list[MAX], tree[MAX * 4];
int init(int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = start;
    }
    int left = init(node * 2, start, (start + end) / 2);
    int right = init(node * 2 + 1, (start + end) / 2 + 1, end);
    return tree[node] = list[left] > list[right] ? right : left;
}
int query(int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return -1;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    int l_idx = query(node * 2, start, (start + end) / 2, left, right);
    int r_idx = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    if(l_idx == -1)
    {
        return r_idx;
    }
    if(r_idx == -1)
    {
        return l_idx;
    }
    return list[l_idx] > list[r_idx] ? r_idx : l_idx;
}
int solve(int start, int end, int left, int right)
{
    int k = query(1, start, end, left, right);
    int ans = list[k] * (right - left + 1);
    if(left < k)
    {
        ans = std::max(ans, solve(start, end, left, k - 1));
    }
    if(right > k)
    {
        ans = std::max(ans, solve(start, end, k + 1, right));
    }
    return ans;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i];
    }
    init(1, 0, n - 1);
    std::cout << solve(0, n - 1, 0, n - 1) << '\n';
}