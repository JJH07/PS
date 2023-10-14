#include <bits/stdc++.h>
const int MAX = 1000000;
int t, n, k, m, parent[MAX];
int find(int idx)
{
    if(parent[idx] < 0)
    {
        return idx;
    }
    return parent[idx] = find(parent[idx]);
}
void connect(int x, int y)
{
    int px = find(x);
    int py = find(y);
    if(px == py)
    {
        return ;
    }
    if(parent[px] < parent[py])
    {
        parent[px] += parent[py];
        parent[py] = px;
    }
    else
    {
        parent[py] += parent[px];
        parent[px] = py;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> t;
    for(int i = 1; i <= t; i++)
    {
        std::memset(parent, -1, sizeof(parent));
        std::cin >> n >> k;
        for(int j = 0; j < k; j++)
        {
            int a, b;
            std::cin >> a >> b;
            connect(a, b);
        }

        std::cout << "Scenario " << i << ":\n";
        std::cin >> m;
        for(int j = 0; j < m; j++)
        {
            int u, v;
            std::cin >> u >> v;
            std::cout << (find(u) == find(v)) << '\n';
        }
        std::cout << '\n';
    }
    return 0;
}