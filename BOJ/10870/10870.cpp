#include <iostream>

int main()
{
    int dp[21], n;
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= 20; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    std::cin >> n;
    std::cout << dp[n] << '\n';
    return 0;
}