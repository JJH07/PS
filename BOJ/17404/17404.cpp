#include <iostream>
#include <algorithm>
const int INF = 1e9;

int n, dp[1001][3][3], price[1001][3];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    for(int i = 1; i <= 1000; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                dp[i][j][k] = INF;
            }
        }
    }

    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cin >> price[i][j];
        }
    }
    
    for(int start = 0; start < 3; start++)
    {
        dp[1][start][start] = price[1][start];
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                dp[i + 1][start][(j + 1) % 3] = std::min(dp[i + 1][start][(j + 1) % 3], dp[i][start][j] + price[i + 1][(j + 1) % 3]);
                dp[i + 1][start][(j + 2) % 3] = std::min(dp[i + 1][start][(j + 2) % 3], dp[i][start][j] + price[i + 1][(j + 2) % 3]); 
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(i == j)
            {
                continue;
            }
            ans = std::min(ans, dp[n][i][j]);
        }
    }
    std::cout << ans << '\n';
    return 0;
}