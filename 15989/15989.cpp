#include <bits/stdc++.h>
int dp[10001];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    dp[0] = 1;
    for(int i = 1; i <= 3; i++)
    {
        for(int j = i; j <= 10000; j++)
        {
            dp[j] += dp[j - i];
        }
    }
    int tc, n;
    std::cin >> tc;
    while(tc--)
    {
        std::cin >> n;
        std::cout << dp[n] << '\n';
    }
    return 0;
}