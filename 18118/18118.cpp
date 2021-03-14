#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
typedef long long ll;
ll n, m, dp[10][100000];
int main()
{   
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--)
    {
        std::memset(dp, -1, sizeof(dp));
        std::cin >> n >> m;
        dp[n][0] = 0;
        for(int idx = n; idx > 0; idx--)
        {
            for(int rest = 0; rest < m; rest++)
            {
                if(dp[idx][rest] == -1)
                {
                    continue;
                }
                for(int number = 0; number <= 9; number++)
                {
                    int nrest = (rest * 10 + number) % m;
                    dp[idx - 1][nrest] = std::max(dp[idx - 1][nrest], dp[idx][rest] * 10 + number);
                }
                int nrest = (rest * 100 + 11) % m;
                dp[idx - 1][nrest] = std::max(dp[idx - 1][nrest], dp[idx][rest] * 100 + 11);
            }
        }
        std::cout << dp[0][0] << '\n';
    }
    return 0;
}