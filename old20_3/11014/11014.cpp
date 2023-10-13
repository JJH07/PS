#include <iostream>
#include <cstring>
#include <vector>
#define MAX 81
#define MAX_T 6401

int n, m, map[MAX][MAX], d[MAX_T];
int dx[6] = {-1, -1, 0, 0, 1, 1}, dy[6] = {-1, 1, -1, 1, -1, 1};
std::vector<int> adj[MAX_T];
bool check[MAX_T];
bool dfs(int x)
{
    if(check[x])
    {
        return false;
    }
    check[x] = true;
    for(int y : adj[x])
    {
        if(d[y] == 0 || dfs(d[y]))
        {
            d[y] = x;
            return true;
        }
    }
    return false;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int tc;
    std::cin >> tc;
    while(tc--)
    {
        std::cin >> n >> m;

        int tot = 0;
        std::vector<int> list;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                char c;
                std::cin >> c;
                if(c == '.')
                {
                    map[i][j] = ++tot;
                    if(j % 2 == 0)
                    {
                        list.push_back(tot);
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(map[i][j] > 0)
                {
                    for(int k = 0; k < 6; k++)
                    {
                        int nx = dx[k] + i;
                        int ny = dy[k] + j;
                        if(nx <= 0 || ny <= 0 || nx > n || ny > m)
                        {
                            continue;
                        }
                        if(map[nx][ny] > 0)
                        {
                            adj[map[i][j]].push_back(map[nx][ny]);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i : list)
        {
            std::memset(check, 0, sizeof(check));
            if(dfs(i))
            {
                ans++;
            }
        }
        std::cout << tot - ans << '\n';
        std::memset(d, 0, sizeof(d));
        std::memset(map, 0, sizeof(map));
        for(int i = 1; i <= tot; i++)
        {
            adj[i].clear();
        }
    }
    return 0;
}