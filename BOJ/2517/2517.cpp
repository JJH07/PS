#include <iostream>
#include <algorithm>
#define MAX 500000

typedef std::pair<int, int> PII;
int n, tree[MAX * 4];
PII list[MAX];
bool comp(const PII &a, const PII &b)
{
    return a.second < b.second;
}
int sum(int node, int start, int end, int left, int right)
{
    if(end < left || right < start)
    {
        return 0;
    }
    if(left <= start && end <= right)
    {
        return tree[node];
    }
    return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
void update(int node, int start, int end, int val)
{
    if(val < start || end < val)
    {
        return ;
    }
    tree[node]++;
    if(start != end)
    {
        update(node * 2, start, (start + end) / 2, val);
        update(node * 2 + 1, (start + end) / 2 + 1, end, val);
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i].first;
        list[i].second = i;
    }
    std::sort(list, list + n);
    for(int i = 0; i < n; i++)
    {
        list[i].first = i;
    }
    std::sort(list, list + n, comp);
    for(int i = 0; i < n; i++)
    {
        std::cout <<  1 + i - sum(1, 0, n - 1, 0, list[i].first) << '\n';
        update(1, 0, n - 1, list[i].first);
    }
    return 0;
}