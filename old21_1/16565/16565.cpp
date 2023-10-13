#include <iostream>
#include <cstring>
#define MOD 10007
int n, dp[53][53];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for(int i = 0; i <= 52; i++)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
        for(int j = 1; j < i; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
    int ans = 0;
    for(int i = 1; i <= 13; i++)
    {
        if(n - 4 * i < 0)
        {
            break;
        }
        ans = (ans + (i % 2 ? 1 : -1) * dp[13][i] * dp[52 - 4 * i][n - 4 * i]) % MOD;
        if(ans < 0)
        {
            ans += MOD;
        }
    }
    std::cout << ans << '\n';
    return 0;
}