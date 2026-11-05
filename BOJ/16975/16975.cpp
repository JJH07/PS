#include <iostream>
#define MAX 100001
#define INF (int)1e9
typedef long long ll;
ll tree[MAX * 4], lazy[MAX * 4];
void propagate(int node, int start, int end)
{
    if(lazy[node] != 0)
    {
        if(start != end)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        tree[node] += lazy[node] * (end - start + 1);
        lazy[node] = 0;
    }
}
ll sum(int node, int start, int end, int idx)
{
    propagate(node, start, end);
    if(idx < start || end < idx)
    {
        return 0;
    }
    if(start == end)
    {
        return tree[node];
    }
    return sum(node * 2, start, (start + end) / 2, idx) + sum(node * 2 + 1, (start + end) / 2 + 1, end, idx);
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
        lazy[node] = val;
        propagate(node, start, end);
        return ;
    }
    update(node * 2, start, (start + end) / 2, left, right, val);
    update(node * 2 + 1, (start + end) / 2 + 1, end, left, right, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int number;
        std::cin >> number;
        update(1, 1, n, i, i, number);
    }
    std::cin >> m;
    while(m--)
    {
        int op, i;
        std::cin >> op >> i;
        if(op == 1)
        {
            int j, k;
            std::cin >> j >> k;
            update(1, 1, n, i, j, k);
        }
        else
        {
            std::cout << sum(1, 1, n, i) << '\n';
        }
    }

    return 0;
}