#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

const int MAX = 51;

struct shark{
    int SZ;
    int SPD;
    int INT;
} sharks[MAX];
std::vector<int> list[MAX];
int n, d[MAX];
bool checked[MAX];

void INIT()
{
    bool adj[MAX][MAX];
    std::memset(adj, 0, sizeof(adj));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
            {
                continue;
            }
            shark &x = sharks[i];
            shark &y = sharks[j];
            if(!adj[j][i] && x.SZ >= y.SZ && x.SPD >= y.SPD && x.INT >= y.INT)
            {
                adj[i][j] = 1;
                list[i].push_back(j);
            }
        }
    }
}
int dfs(int s)
{
    for(int next : list[s])
    {
        if(checked[next])
        {
            continue;
        }
        checked[next] = 1;
        if(d[next] == 0 || dfs(d[next]))
        {
            d[next] = s;
            return 1;
        }
    }
    return 0;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> sharks[i].SZ >> sharks[i].SPD >> sharks[i].INT;
    }
    INIT();
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        std::memset(checked, 0, sizeof(checked));
        if(dfs(i))
        {
            ans++;
        }
        std::memset(checked, 0, sizeof(checked));
        if(dfs(i))
        {
            ans++;
        }
    }
    std::cout << n - ans << '\n';
    return 0;
}