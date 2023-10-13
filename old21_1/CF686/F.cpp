#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
typedef std::pair<int, int> PII;
int n;
std::vector<int> list;
std::vector<PII> tree;
void init(int node, int start, int end)
{
    if(start == end)
    {
        tree[node] = {list[start], list[start]};
        return;
    }
    init(node * 2, start, (start + end) / 2);
    init(node * 2 + 1, (start + end) / 2 + 1, end);
    tree[node] = {std::min(tree[node * 2].first, tree[node * 2 + 1].first), std::max(tree[node * 2].second, tree[node * 2 + 1].second)};
}
PII minmax(int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return {INT_MAX, INT_MIN};
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    PII L = minmax(node * 2, start, (start + end) / 2, left, right);
    PII R = minmax(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    return {std::min(L.first, R.first), std::max(L.second, R.second)};
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        std::cin >> n;
        list.resize(n);
        tree.resize(n * 4);
        for(int i = 0; i < n; i++)
        {
            std::cin >> list[i];
        }
        init(1, 0, n - 1);

    }
    return 0;
}