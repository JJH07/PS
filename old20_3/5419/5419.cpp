#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

typedef long long ll;
struct point{
    ll x;
    ll y;
    int idx;
};
bool sort_x(const point &a, const point &b)
{
    return a.x != b.x ? a.x < b.x : a.y > b.y;
}
bool sort_y(const point &a, const point &b)
{
    return a.y != b.y ? a.y > b.y : a.x < b.x;
}
ll init(std::vector<ll> &tree, int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = 1;
    }
    return tree[node] = init(tree, node * 2, start, (start + end) / 2) + init(tree, node * 2 + 1, (start + end) / 2 + 1, end);
}
ll sum(std::vector<ll> &tree, int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update(std::vector<ll> &tree, int node, int start, int end, int idx)
{
    if(end < idx || idx < start)
    {
        return ;
    }
    tree[node]--;
    if(start != end)
    {
        update(tree, node * 2, start, (start + end) / 2, idx);
        update(tree, node * 2 + 1, (start + end) / 2 + 1, end, idx);
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int n;
        ll ans = 0;
        std::cin >> n;
        std::vector<point> list(n);
        std::vector<ll> tree(1 << ((int)ceil(log2(n)) + 1), 0);
        for(int i = 0; i < n; i++)
        {
            std::cin >> list[i].x >> list[i].y;
        }

        std::sort(list.begin(), list.end(), sort_x);
        for(int i = 0; i < n; i++)
        {
            list[i].idx = i;
        }
        
        init(tree, 1, 0, n - 1);

        std::sort(list.begin(), list.end(), sort_y);
        for(int i = 0; i < n; i++)
        {
            int idx = list[i].idx;
            ans += (sum(tree, 1, 0, n - 1, idx, n - 1) - 1);
            update(tree, 1, 0, n - 1, idx);
        }
        std::cout << ans << '\n';
    }

    return 0;
}