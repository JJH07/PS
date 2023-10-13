#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 53
#define MAXLINE 2503

int n, m, X[MAX][MAX], Y[MAX][MAX], d[MAXLINE];
char map[MAX][MAX];
std::vector<int> adj[MAXLINE];
bool check[MAXLINE];

bool dfs(int i)
{
    if(check[i])
    {
        return false;
    }
    check[i] = true;
    for(auto j : adj[i])
    {
        if(d[j] == 0 || dfs(d[j]))
        {
            d[j] = i;
            return true;
        }
    }
    return false;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        std::string tmp;
        std::cin >> tmp;
        for(int j = 1; j <= m; j++)
        {
            map[i][j] = tmp[j - 1];
        }
    }

    int L_MAX = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(map[i][j] == '.')
            {
                continue;
            }
            if(map[i][j - 1] != '*')
            {
                L_MAX++;
            }
            X[i][j] = L_MAX;
        }
    }
    int R_MAX = 0;
    for(int j = 1; j <= m; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(map[i][j] == '.')
            {
                continue;
            }
            if(map[i - 1][j] != '*')
            {
                R_MAX++;
            }
            Y[i][j] = R_MAX;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(map[i][j] == '.')
            {
                continue;
            }
            adj[X[i][j]].push_back(Y[i][j]);
        }
    }
    int ans = 0;
    for(int i = 1; i <= L_MAX; i++)
    {
        std::memset(check, 0, sizeof(check));
        if(dfs(i))
        {
            ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}