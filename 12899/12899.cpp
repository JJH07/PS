#include <bits/stdc++.h>
#define MAX 2000000

int tree[MAX * 4];
void update(int node, int start, int end, int idx, int val)
{
    if(idx < start || end < idx)
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
int search(int node, int start, int end, int nth)
{
    if(start == end)
    {
        return start;
    }
    if(nth <= tree[node * 2])
    {
        return search(node * 2, start, (start + end) / 2, nth);
    }
    return search(node * 2 + 1, (start + end) / 2 + 1, end, nth - tree[node * 2]);
}
int query(int nth)
{
    int k = search(1, 1, MAX, nth);
    update(1, 1, MAX, k, -1);
    return k;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    while(n--)
    {
        int T, X;
        std::cin >> T >> X;
        if(T == 1)
        {
            update(1, 1, MAX, X, 1);
        }
        else
        {
            std::cout << query(X) << '\n';
        }
    }
    return 0;
}