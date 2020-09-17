#include <iostream>
#include <vector>
#include <cmath>
const int MAX_D = 16;
std::vector<std::vector<int>> link(50001);
int level[50001], parent[50001][MAX_D];
void dfs(int idx, int lev)
{
    for(auto next : link[idx])
    {
        if(level[next] == 0)
        {
            level[next] = lev + 1;
            parent[next][0] = idx;
            dfs(next, lev + 1);
        }
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        std::cin >> a >> b;
        link[a].push_back(b);
        link[b].push_back(a);
    }

    level[1] = 1;
    dfs(1, 1);

    for(int j = 0; j < MAX_D - 1; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(parent[i][j] > 0)
            {
                parent[i][j + 1] = parent[parent[i][j]][j];
            }
        }
    }
    std::cin >> m;
    while(m--)
    {
        int x, y;
        std::cin >> x >> y;
        if(level[x] > level[y])
        {
            std::swap(x, y);
        }
        int diff = level[y] - level[x];
        for(int i = 0; diff > 0; i++)
        {
            if(diff % 2)
            {
                y = parent[y][i];
            }
            diff /= 2;
        }
        if(x != y)
        {
            for(int i = MAX_D - 1; i >= 0; i--)
            {
                if(parent[x][i] > 0 && parent[x][i] != parent[y][i])
                {
                    x = parent[x][i];
                    y = parent[y][i];
                }
            }
            x = parent[x][0];
        }
        std::cout << x << '\n';
    }
    return 0;
}