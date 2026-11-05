#include <bits/stdc++.h>
#define MAX 100000

int tree[MAX * 4];
void Update(int node, int start, int end, int idx, int is_Even)
{
    if(idx < start || end < idx)
    {
        return ;
    }
    if(start == end)
    {
        tree[node] = is_Even;
        return ;
    }
    Update(node * 2, start, (start + end) / 2, idx, is_Even);
    Update(node * 2 + 1, (start + end) / 2 + 1, end, idx, is_Even);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int Even(int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return Even(node * 2, start, (start + end) / 2, left, right) + Even(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int number;
        std::cin >> number;
        Update(1, 0, n - 1, i, (number + 1) % 2);
    }
    std::cin >> m;
    while(m--)
    {
        int op, a, b;
        std::cin >> op >> a >> b;
        if(op == 1)
        {
            Update(1, 0, n - 1, a - 1, (b + 1) % 2);
        }
        else if(op == 2)
        {
            std::cout << Even(1, 0, n - 1, a - 1, b - 1) << '\n';
        }
        else
        {
            std::cout << (b - a + 1) - Even(1, 0, n - 1, a - 1, b - 1) << '\n';
        }
    }
    return 0;
}