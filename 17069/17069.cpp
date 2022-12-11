#include <bits/stdc++.h>
#define MAX 34
typedef long long ll;
int wall[MAX][MAX];
ll dp[MAX][MAX][3];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    dp[1][1][0] = 1;
    dp[1][2][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cin >> wall[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 2; j <= n; j++)
        {
            for(int t = 0; t < 3; t++)
            {
                if(!dp[i][j][t])
                {
                    continue;
                }
                if(!wall[i][j + 1] && !wall[i + 1][j] && !wall[i + 1][j + 1])
                {
                    dp[i + 1][j + 1][1] += dp[i][j][t];
                }
                if(t == 0 || t == 1)
                {
                    if(!wall[i][j + 1])
                    {
                        dp[i][j + 1][0] += dp[i][j][t];
                    }
                }
                if(t == 2 || t == 1)
                {
                    if(!wall[i + 1][j])
                    {
                        dp[i + 1][j][2] += dp[i][j][t];
                    }
                }
            }
        }
    }
    ll ans = dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    std::cout << ans << '\n';
}