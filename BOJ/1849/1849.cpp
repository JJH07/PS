#include <iostream>
constexpr int MAX = 100001;
int tree[MAX * 4], order[MAX];
int buildTree(int node, int start, int end)
{
    if(start == end)
    {
        return tree[node] = 1;
    }
    return tree[node] = buildTree(node * 2, start, (start + end) / 2) + buildTree(node * 2 + 1, (start + end) / 2 + 1, end);
}
int takeKth(int node, int start, int end, int rank)
{
    tree[node]--;
    if(start == end)
    {
        return start;
    }
    const int mid = (start + end) / 2;
    if(rank <= tree[node * 2])
    {
        return takeKth(node * 2, start, mid, rank);
    }
    return takeKth(node * 2 + 1, mid + 1, end, rank - tree[node * 2]);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    buildTree(1, 1, n);
    for(int i = 1; i <= n; i++)
    {
        int skipped;
        std::cin >> skipped;
        int pos = takeKth(1, 1, n, skipped + 1);
        order[pos] = i;
    }
    for(int i = 1; i <= n; i++)
    {
        std::cout << order[i] << '\n';
    }
    return 0;
}
