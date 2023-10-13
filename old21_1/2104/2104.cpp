#include <iostream>
#define MAX 100001
#define INF 1e18
typedef long long ll;
typedef std::pair<ll, int> pli;
int n;
ll list[MAX], sum[MAX];
pli tree[MAX * 4];
pli init(int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = {list[start], start};
    }
    pli left = init(node * 2, start, (start + end) / 2);
    pli right = init(node * 2 + 1, (start + end) / 2 + 1, end);
    return tree[node] = left.first <= right.first ? left : right;
}
pli Min(int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return {INF, -1};
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    pli l = Min(node * 2, start, (start + end) / 2, left, right);
    pli r = Min(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    return l.first <= r.first ? l : r;
}
ll query(int left, int right)
{
    if(left > right)
    {
        return 0;
    }
    if(left == right)
    {
        return list[left] * list[left];
    }
    pli now = Min(1, 1, n, left, right);
    ll ret = now.first * (sum[right] - sum[left - 1]);
    ret = std::max(ret, query(left, now.second - 1));
    ret = std::max(ret, query(now.second + 1, right));
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> list[i];
        sum[i] = sum[i - 1] + list[i];
    }
    init(1, 1, n);
    ll ans = query(1, n);
    std::cout << ans << '\n';
    return 0;
}