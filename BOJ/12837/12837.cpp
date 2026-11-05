#include <iostream>
#define MAX 1000001
typedef long long ll;
ll tree[MAX * 4];
ll sum(int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update(int node, int start, int end, int idx, ll val)
{
    if(end < idx || idx < start)
    {
        return ;
    }
    tree[node] += val;
    if(start != end)
    {
        update(node * 2, start, (start + end) / 2, idx, val);
        update(node * 2 + 1, (start + end) / 2 + 1, end, idx, val);
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q;
    std::cin >> n >> q;
    while(q--)
    {
        int op, i, j;
        std::cin >> op >> i >> j;
        if(op == 1)
        {
            update(1, 1, n, i, j);
        }
        else
        {
            std::cout << sum(1, 1, n, i, j) << '\n';
        }        
    }
    return 0;
}