#include <bits/stdc++.h>
#define MAX 1000001
int n, m, list[MAX], tree[MAX * 4];
int init(int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = list[start];
    }
    return tree[node] = std::max(init(node * 2, start, (start + end) / 2), init(node * 2 + 1, (start + end) / 2 + 1, end));
}
int max(int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return std::max(max(node * 2, start, (start + end) / 2, left, right), max(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> list[i];
    }
    init(1, 1, n);
    for(int i = m; i <= n - m + 1; i++)
    {
        std::cout << max(1, 1, n, i - m + 1, i + m - 1) << ' ';
    }
    std::cout << '\n';
    return 0;
}