#include <iostream>
#include <algorithm>
#define MAX 100001
#define INF (int)1e9
typedef std::pair<int, int> pii;
int list[MAX];
pii tree[MAX * 4];
pii init(int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = {list[start], start};
    }
    return tree[node] = std::min(init(node * 2, start, (start + end) / 2), init(node * 2 + 1, (start + end) / 2 + 1, end));
}
pii min(int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return {INF, INF};
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return std::min(min(node * 2, start, (start + end) / 2, left, right), min(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
void update(int node, int start, int end, int idx, int val)
{
    if(idx < start || end < idx)
    {
        return ;
    }
    if(start != end)
    {
        update(node * 2, start, (start + end) / 2, idx, val);
        update(node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
        tree[node] = std::min(tree[node * 2], tree[node * 2 + 1]);
    }
    else
    {
        tree[node] = {list[start], start};
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> list[i];
    }
    init(1, 1, n);
    std::cin >> m;
    while(m--)
    {
        int op, i, j;
        std::cin >> op >> i >> j;
        if(op == 1)
        {
            list[i] = j;
            update(1, 1, n, i, j);
        }
        else
        {
            std::cout << min(1, 1, n, i, j).second << '\n';
        }
    }
    return 0;
}