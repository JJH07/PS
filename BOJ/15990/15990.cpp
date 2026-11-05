#include <iostream>
#include <cstring>
#define MAX 100001
#define MOD 1000000009
typedef long long ll;
int n;
ll dp[MAX + 5][4];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][3] = 1;
    for(int now = 1; now < MAX; now++)
    {
        for(int before = 1; before <= 3; before++)
        {
            for(int next = 1; next <= 3; next++)
            {
                if(before != next)
                {
                    dp[now + next][next] = (dp[now + next][next] + dp[now][before]) % MOD;
                }
            }
        }
    }
    int T;
    std::cin >> T;
    while(T--)
    {
        std::cin >> n;
        ll ans = (dp[n][1] + dp[n][2] + dp[n][3]) % MOD;
        std::cout << ans << '\n';
    }
    return 0;
}