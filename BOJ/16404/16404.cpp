#include <bits/stdc++.h>
#define MAX 100001
typedef long long ll;
int n, m, IN[MAX], OUT[MAX], indexing;
ll tree[MAX * 4], lazy[MAX * 4];
std::vector<int> sub[MAX];
void dfs(int now)
{
    IN[now] = ++indexing;
    for(int next : sub[now])
    {
        dfs(next);
    }
    OUT[now] = indexing;
}
void propagate(int node, int start, int end)
{
    if(lazy[node] == 0)
    {
        return ;
    }
    if(start != end)
    {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    tree[node] += lazy[node] * (end - start + 1);
    lazy[node] = 0;
}
ll balance(int node, int start, int end, int left, int right)
{
    propagate(node, start, end);
    if(end < left || right < start)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return balance(node * 2, start, (start + end) / 2, left, right) + balance(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update(int node, int start, int end, int left, int right, ll val)
{
    propagate(node, start, end);
    if(end < left || right < start)
    {
        return ;
    }
    if(left <= start && end <= right)
    {
        lazy[node] += val;
        propagate(node, start, end);
        return ;
    }
    update(node * 2, start, (start + end) / 2, left, right, val);
    update(node * 2 + 1, (start + end) / 2 + 1, end, left, right, val);
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int boss;
        std::cin >> boss;
        if(boss == -1)
        {
            continue;
        }
        sub[boss].push_back(i);
    }
    for(int i = 1; i <= n; i++)
    {
        if(IN[i] == 0)
        {
            dfs(i);
        }
    }
    while(m--)
    {
        int op, i;
        std::cin >> op >> i;
        if(op == 1)
        {
            ll w;
            std::cin >> w;
            update(1, 1, n, IN[i], OUT[i], w);
        }
        else
        {
            ll ans = balance(1, 1, n, IN[i], IN[i]);
            std::cout << ans << '\n';
        }
    }
    return 0;
}