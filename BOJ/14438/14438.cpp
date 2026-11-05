#include <iostream>
#include <algorithm>
#define MAX 100000
#define INF 1e9
int list[MAX], tree[MAX * 4];
int init(int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = list[start];
    }
    return tree[node] = std::min(init(node * 2, start, (start + end) / 2), init(node * 2 + 1, (start + end) / 2 + 1, end));
}
int Min(int node, int start, int end, int left, int right)
{
    if(right < start || end < left)
    {
        return INF;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return std::min(Min(node * 2, start, (start + end) / 2, left, right), Min(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
void update(int node, int start, int end, int idx, int val)
{
    if(end < idx || idx < start)
    {
        return ;
    }
    if(start == end)
    {
        tree[node] = list[start];
        return ;
    }
    if(start != end)
    {
        update(node * 2, start, (start + end) / 2, idx, val);
        update(node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
    }
    tree[node] = std::min(tree[node * 2], tree[node * 2 + 1]);
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i];
    }
    init(1, 0, n - 1);
    std::cin >> m;
    while(m--)
    {
        int op, i, j;
        std::cin >> op >> i >> j;
        if(op == 1)
        {
            list[i - 1] = j;
            update(1, 0, n - 1, i - 1, j);
        }
        else
        {
            std::cout << Min(1, 0, n - 1, i - 1, j - 1) << '\n';
        }
        
    }
    return 0;
}