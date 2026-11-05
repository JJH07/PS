#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 500000
int n, m, tree[MAX * 4], lazy[MAX * 4];
void propagate(int node, int start, int end)
{
    if(lazy[node] == 0)
    {
        return ;
    }
    if(start != end)
    {
        lazy[node * 2] ^= lazy[node];
        lazy[node * 2 + 1] ^= lazy[node];
    }
    tree[node] ^= lazy[node];
    lazy[node] = 0;
}
void update(int node, int start, int end, int left, int right, int val)
{
    propagate(node, start, end);
    if(end < left || right < start)
    {
        return ;
    }
    if(left <= start && end <= right)
    {
        lazy[node] ^= val;
        propagate(node, start, end);
        return ;
    }
    update(node * 2, start, (start + end) / 2, left, right, val);
    update(node * 2 + 1, (start + end) / 2 + 1, end, left, right, val);
}
int Query(int node, int start, int end, int idx)
{
    propagate(node, start, end);
    if(end < idx || idx < start)
    {
        return -1;
    }
    if(idx <= start && end <= idx)
    {
        return tree[node];
    }
    return std::max(Query(node * 2, start, (start + end) / 2, idx), Query(node * 2 + 1, (start + end) / 2 + 1, end, idx));
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int val;
        std::cin >> val;
        update(1, 0, n - 1, i, i, val);
    }
    std::cin >> m;
    for(int i = 0; i < m; i++)
    {
        int t, a;
        std::cin >> t >> a;
        if(t == 1)
        {
            int b, c;
            std::cin >> b >> c;
            update(1, 0, n - 1, a, b, c);
        }
        else
        {
            std::cout << Query(1, 0, n - 1, a) << '\n';
        }
    }
    return 0;
}