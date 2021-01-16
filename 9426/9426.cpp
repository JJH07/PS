#include <iostream>
#include <algorithm>
#define MAX 250001
#define T_MAX 65536
typedef long long ll;
int list[MAX];
ll tree[T_MAX * 4];
void update(int node, int start, int end, int idx, int val)
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
ll count(int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return count(node * 2, start, (start + end) / 2, left, right) + count(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
ll query(int m)
{
    int l = 0, r = 65535;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        ll c = count(1, 0, 65535, 0, mid);
        if(c < m)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return l;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    ll ans = 0;
    std::cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> list[i];
    }
    for(int i = 1; i <= n; i++)
    {
        update(1, 0, 65535, list[i], 1);
        if(i >= k)
        {
            ans += query((k + 1) / 2);
            update(1, 0, 65535, list[i - k + 1], -1);
        }
    }
    std::cout << ans << '\n';
    return 0;
}