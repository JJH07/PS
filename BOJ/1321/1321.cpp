#include <iostream>

constexpr int MAX_N = 500000;
int tree[MAX_N * 4];

void build(int node, int start, int end)
{
    if(start == end)
    {
        std::cin >> tree[node];
        return;
    }
    const int mid = (start + end) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int start, int end, int index, int delta)
{
    tree[node] += delta;
    if(start == end)
    {
        return;
    }
    const int mid = (start + end) / 2;
    if(index <= mid)
    {
        update(node * 2, start, mid, index, delta);
    }
    else
    {
        update(node * 2 + 1, mid + 1, end, index, delta);
    }
}

int findKth(int node, int start, int end, int rank)
{
    if(start == end)
    {
        return start;
    }
    const int mid = (start + end) / 2;
    const int leftCount = tree[node * 2];
    if(rank <= leftCount)
    {
        return findKth(node * 2, start, mid, rank);
    }
    return findKth(node * 2 + 1, mid + 1, end, rank - leftCount);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n;
    build(1, 1, n);
    std::cin >> m;
    while(m--)
    {
        int op, value;
        std::cin >> op >> value;
        if(op == 1)
        {
            int delta;
            std::cin >> delta;
            update(1, 1, n, value, delta);
        }
        else
        {
            std::cout << findKth(1, 1, n, value) << '\n';
        }
    }
    return 0;
}
