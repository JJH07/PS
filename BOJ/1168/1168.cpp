#include <iostream>

constexpr int MAX_N = 100000;
int tree[MAX_N * 4];

void build(int node, int start, int end)
{
    tree[node] = end - start + 1;
    if(start == end)
    {
        return;
    }
    const int mid = (start + end) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);
}

int removeKth(int node, int start, int end, int rank)
{
    tree[node]--;
    if(start == end)
    {
        return start;
    }
    const int mid = (start + end) / 2;
    const int leftCount = tree[node * 2];
    if(rank <= leftCount)
    {
        return removeKth(node * 2, start, mid, rank);
    }
    return removeKth(node * 2 + 1, mid + 1, end, rank - leftCount);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    build(1, 1, n);

    int rank = 1;
    std::cout << '<';
    for(int remaining = n; remaining > 0; remaining--)
    {
        rank = (rank + k - 2) % remaining + 1;
        std::cout << removeKth(1, 1, n, rank);
        if(remaining > 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << ">\n";
    return 0;
}
