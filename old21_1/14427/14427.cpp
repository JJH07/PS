#include <iostream>
#define MAX 100001
#define INF (int)1e9

int list[MAX], tree[MAX * 4];
int init(int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = start;
    }
    int left = init(node * 2, start, (start + end) / 2);
    int right = init(node * 2 + 1, (start + end) / 2 + 1, end);
    return tree[node] = (list[left] <= list[right] ? left : right);
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
        tree[node] = (list[tree[node * 2]] <= list[tree[node * 2 + 1]] ? tree[node * 2] : tree[node * 2 + 1]);
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
    for(int i = 1; i <= m; i++)
    {
        int op;
        std::cin >> op;
        if(op == 1)
        {
            int a, b;
            std::cin >> a >> b;
            list[a] = b;
            update(1, 1, n, a, b);
        }
        else
        {
            std::cout << tree[1] << '\n';
        }
    }
    return 0;
}