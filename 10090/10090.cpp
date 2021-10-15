#include <bits/stdc++.h>
#define MAX 1000000
typedef long long ll;

ll tree[MAX * 4];
void Update(int node, int start, int end, int idx)
{
    if(idx < start || end < idx)
    {
        return ;
    }
    if(start == end)
    {
        tree[node] = 1;
        return ;
    }
    Update(node * 2, start, (start + end) / 2, idx);
    Update(node * 2 + 1, (start + end) / 2 + 1, end, idx);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
ll Query(int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return Query(node * 2, start, (start + end) / 2, left, right) + Query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    ll answer = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll number;
        std::cin >> number;
        answer += Query(1, 1, n, number, n);
        Update(1, 1, n, number);
    }
    std::cout << answer << '\n';
    return 0;
}