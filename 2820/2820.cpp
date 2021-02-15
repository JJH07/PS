#include <iostream>
#include <vector>
#define MAX 500001
typedef long long ll;
int n, m, in[MAX], out[MAX], indexing;
ll Wage[MAX], tree[MAX * 4], lazy[MAX * 4];
std::vector<int> link[MAX];
void dfs(int now)
{
    in[now] = ++indexing;
    for(auto next : link[now])
    {
        dfs(next);
    }
    out[now]= indexing;
}
void propagate(int node, int start, int end)
{
    if(lazy[node] == 0)
    {
        return ;
    }
    tree[node] += lazy[node] * (end - start + 1);
    if(start != end)
    {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
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
        lazy[node] += val;
        propagate(node, start, end);
        return ;
    }
    if(start != end)
    {
        update(node * 2, start, (start + end) / 2, left, right, val);
        update(node * 2 + 1, (start + end) / 2 + 1, end, left, right, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}
ll query(int node, int start, int end, int idx)
{
    propagate(node, start, end);
    if(idx < start || end < idx)
    {
        return 0;
    }
    if(idx <= start && end <= idx)
    {
        return tree[node];
    }
    return query(node * 2, start, (start + end) / 2, idx) + query(node * 2 + 1, (start + end) / 2 + 1, end, idx);
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m >> Wage[1];
    for(int i = 2; i <= n; i++)
    {
        int Boss;
        std::cin >> Wage[i] >> Boss;
        link[Boss].push_back(i);
    }
    dfs(1);
    while(m--)
    {
        char op;
        int a, x;
        std::cin >> op >> a;
        if(op == 'p')
        {
            std::cin >> x;
            if(in[a] == out[a])
            {
                continue;
            }
            update(1, 1, n, in[a] + 1, out[a], x);
        }
        else
        {
            ll ans = Wage[a] + query(1, 1, n, in[a]);
            std::cout << ans << '\n';
        }
        
    }
    return 0;
}