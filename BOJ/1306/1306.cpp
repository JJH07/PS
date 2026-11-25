#include <algorithm>
#include <iostream>

constexpr int MAX = 1000001;
int n, m, brightness[MAX], tree[MAX * 4];
int build(int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = brightness[start];
    }
    const int mid = (start + end) / 2;
    return tree[node] = std::max(build(node * 2, start, mid), build(node * 2 + 1, mid + 1, end));
}
int queryMax(int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    const int mid = (start + end) / 2;
    return std::max(queryMax(node * 2, start, mid, left, right), queryMax(node * 2 + 1, mid + 1, end, left, right));
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> brightness[i];
    }
    build(1, 1, n);
    for(int i = m; i <= n - m + 1; i++)
    {
        std::cout << queryMax(1, 1, n, i - m + 1, i + m - 1) << ' ';
    }
    std::cout << '\n';
    return 0;
}
