#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 101

int n, m, X[MAX][MAX], Y[MAX][MAX], d[MAX * 10];
bool blocked[MAX][MAX], check[MAX * 10];
std::vector<int> adj[MAX * 10];
bool dfs(int x)
{
    if(check[x])
    {
        return false;
    }
    check[x] = true;
    for(auto y : adj[x])
    {
        if(d[y] == 0 || dfs(d[y]))
        {
            d[y] = x;
            return true;
        }
    }
    return false;
}
int get_X()
{
    int cnt = 1;
    for(int sum = 2; sum <= n * 2; sum++)
    {
        bool FOUND = false;
        for(int j = 1; j <= n; j++)
        {
            int i = sum - j;
            if(i < 1 || i > n || j < 1 || j > n)
            {
                continue;
            }
            if(blocked[i][j])
            {
                if(FOUND)
                {
                    cnt++;
                    FOUND = false;
                }
                continue;
            }
            X[i][j] = cnt;
            FOUND = true;
        }
        if(FOUND)
        {
            cnt++;
        }
    }
    return cnt;
}
int get_Y()
{
    int cnt = 1;
    for(int sum = 1; sum < n * 2; sum++)
    {
        bool FOUND = false;
        for(int i = 1; i <= n; i++)
        {
            int j = sum + i - n;
            if(i < 1 || i > n || j < 1 || j > n)
            {
                continue;
            }
            if(blocked[i][j])
            {
                if(FOUND)
                {
                    cnt++;
                    FOUND = false;
                }
                continue;
            }
            Y[i][j] = cnt;
            FOUND = true;
        }
        if(FOUND)
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        blocked[a][b] = 1;
    }
    
    int L_MAX = get_X();
    int R_MAX = get_Y();

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(!blocked[i][j])
            {
                adj[X[i][j]].push_back(Y[i][j]);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < L_MAX; i++)
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