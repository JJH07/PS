#include <iostream>
#define MAX 15001001
int dp[MAX], ans;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int t, p;
        std::cin >> t >> p;
        dp[i + t - 1] = std::max(dp[i + t - 1], dp[i - 1] + p);
        dp[i] = std::max(dp[i - 1], dp[i]);
    }
    std::cout << dp[n] << '\n';
    return 0;
}