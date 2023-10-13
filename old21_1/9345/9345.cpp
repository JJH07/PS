#include <iostream>
#include <cstring>
#include <climits>
#define MAX 100000
typedef std::pair<int, int> pii;
int shelf[MAX];
pii tree[MAX * 4];
pii init(int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = {start, start};
    }
    pii left = init(node * 2, start, (start + end) / 2);
    pii right = init(node * 2 + 1, (start + end) / 2 + 1, end);
    return tree[node] = {std::min(left.first, right.first), std::max(left.second, right.second)};
}
void update(int node, int start, int end, int a, int b)
{
    if((a < start || end < a) && (b < start || end < b))
    {
        return ;
    }
    if(start == end)
    {
        tree[node] = {shelf[start], shelf[start]};
        return ;
    }
    update(node * 2, start, (start + end) / 2, a, b);
    update(node * 2 + 1, (start + end) / 2 + 1, end, a, b);
    pii l = tree[node * 2];
    pii r = tree[node * 2 + 1];
    tree[node] = {std::min(l.first, r.first), std::max(l.second, r.second)};
}
pii rent(int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return {INT_MAX, INT_MIN};
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    pii l = rent(node * 2, start, (start + end) / 2, left, right);
    pii r = rent(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    return {std::min(l.first, r.first), std::max(l.second, r.second)};
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {   
        int n, k;
        std::cin >> n >> k;
        for(int i = 0; i < n; i++)
        {
            shelf[i] = i;
        }
        init(1, 0, n - 1);
        for(int i = 0; i < k; i++)
        {
            int q, a, b;
            std::cin >> q >> a >> b;            
            if(q == 0)
            {
                std::swap(shelf[a], shelf[b]);
                update(1, 0, n - 1, a, b);
            }
            else
            {
                pii list = rent(1, 0, n - 1, a, b);
                std::cout << (list.first == a && list.second == b ? "YES\n" : "NO\n");
            }
        }
    }
    return 0;
}