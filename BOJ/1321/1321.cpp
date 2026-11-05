#include <bits/stdc++.h>
#define MAX 500000

int tree[MAX * 4];

void update(int node, int start, int end, int idx, int val)
{
    if(end < idx || idx < start)
    {
        return ;
    }
    if(start == end)
    {
        tree[node] += val;
        return ;
    }
    update(node * 2, start, (start + end) / 2, idx, val);
    update(node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int query(int node, int start, int end, int nth)
{
    if(start == end)
    {
        return start;
    }
    if(nth <= tree[node * 2])
    {
        return query(node * 2, start, (start + end) / 2, nth);
    }
    return query(node * 2 + 1, (start + end) / 2 + 1, end, nth - tree[node * 2]);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int t;
        std::cin >> t;
        update(1, 1, n, i, t);
    }
    std::cin >> m;
    while(m--)
    {
        int op, i, a;
        std::cin >> op >> i;
        if(op == 1)
        {
            std::cin >> a;
            update(1, 1, n, i, a);
        }
        else
        {
            std::cout << query(1, 1, n, i) << '\n';
        }
    }
    return 0;
}