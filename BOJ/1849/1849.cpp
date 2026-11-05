#include <iostream>
#define MAX 100001
int tree[MAX * 4], ans[MAX];
int init(int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = 1;
    }
    return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}
int query(int node, int start, int end, int idx)
{
    if(start == end)
    {
        return start;
    }
    if(tree[node * 2] >= idx)
    {
        return query(node * 2, start, (start + end) / 2, idx);
    }
    return query(node * 2 + 1, (start + end) / 2 + 1, end, idx - tree[node * 2]);
}
void update(int node, int start, int end, int idx)
{
    if(end < idx || idx < start)
    {
        return;
    }
    if(start == end)
    {
        tree[node] = 0;
        return;
    }
    if(start != end)
    {
        update(node * 2, start, (start + end) / 2, idx);
        update(node * 2 + 1, (start + end) / 2 + 1, end, idx);
    }
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    init(1, 1, n);
    for(int i = 1; i <= n; i++)
    {
        int idx;
        std::cin >> idx;
        int j = query(1, 1, n, idx + 1);
        ans[j] = i;
        update(1, 1, n, j);
    }
    for(int i = 1; i <= n; i++)
    {
        std::cout << ans[i] << '\n';
    }
    return 0;
}