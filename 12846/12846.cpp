#include <bits/stdc++.h>
#define MAX 100001
#define INF 1000001
typedef long long ll;

int n, list[MAX], tree[MAX * 4];

int init(int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = start;
    }
    int mid = (start + end) / 2;
    int l = init(node * 2, start, mid);
    int r = init(node * 2 + 1, mid + 1, end);
    return tree[node] = list[l] < list[r] ? l : r;
}
int query(int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return -1;
    }
    else if(left <= start && end <= right)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int l = query(node * 2, start, mid, left, right);
    int r = query(node * 2 + 1, mid + 1, end, left, right);
    if(l == -1)
    {
        return r;
    }
    if(r == -1)
    {
        return l;
    }
    return list[l] < list[r] ? l : r;
}
ll search(int start, int end, int left, int right)
{
    int idx = query(1, start, end, left, right);
    ll ret = 1LL * (right - left + 1) * list[idx];
    if(left < idx)
    {
        ret = std::max(ret, search(start, end, left, idx - 1));
    }
    if(idx < right)
    {
        ret = std::max(ret, search(start, end, idx + 1, right));
    }
    return ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    tree[0] = INF;
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> list[i];
    }

    init(1, 1, n);
    ll ans = search(1, n, 1, n);
    std::cout << ans << '\n';
    return 0;
}