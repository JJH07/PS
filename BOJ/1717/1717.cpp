#include <iostream>
#include <algorithm>

int parent[1000001];
int findRoot(int idx)
{
    if(parent[idx] < 0)
    {
        return idx;
    }
    return parent[idx] = findRoot(parent[idx]);
}
void unite(int a, int b)
{
    a = findRoot(a);
    b = findRoot(b);
    if(a == b)
    {
        return;
    }
    if(parent[a] > parent[b])
    {
        parent[b] += parent[a];
        parent[a] = b;
    }
    else
    {
        parent[a] += parent[b];
        parent[b] = a;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::fill(parent, parent + n + 1, -1);
    while(m--)
    {
        int op, a, b;
        std::cin >> op >> a >> b;
        if(op)
        {
            std::cout << (findRoot(a) == findRoot(b) ? "YES\n" : "NO\n");
        }
        else
        {
            unite(a, b);
        }

    }

    return 0;
}
