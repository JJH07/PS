#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1005
int n, m, map[MAX][MAX], dp[MAX][MAX][2];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::fill(dp[0][0], dp[0][0] + MAX * MAX * 2, -100000001);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            std::cin >> map[i][j];
        }
    }
    dp[1][0][0] = 0;
    dp[1][0][1] = 0;
    for(int i = 1; i <= m; i++)
    {
        dp[1][i][0] = dp[1][i - 1][0] + map[1][i];
        dp[1][i][1] = dp[1][i - 1][1] + map[1][i];
    }
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[i][j][0] = std::max(dp[i - 1][j][0], dp[i][j - 1][0]) + map[i][j];
        }
        for(int j = m; j >= 1; j--)
        {
            dp[i][j][1] = std::max(dp[i - 1][j][1], dp[i][j + 1][1]) + map[i][j];
        }
        for(int j = 1; j <= m; j++)
        {
            dp[i][j][0] = dp[i][j][1] = std::max(dp[i][j][0], dp[i][j][1]);
        }
    }
    std::cout << dp[n][m][0] << '\n';
    return 0;
}