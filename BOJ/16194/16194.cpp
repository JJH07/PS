#include <iostream>
#include <algorithm>
#define MAX 1001
#define INF 1e9

int P[MAX], dp[MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::fill(dp, dp + MAX, INF);

    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> P[i];
    }
    dp[n] = 0;
    for(int i = n; i > 0; i--)
    {
        if(dp[i] != INF)
        {
            for(int j = 1; j <= i; j++)
            {
                dp[i - j] = std::min(dp[i - j], dp[i] + P[j]);
            }
        }
    }
    std::cout << dp[0] << '\n';
    return 0;
}