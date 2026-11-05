#include <iostream>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, dp[1005];
    std::cin >> n;
    dp[0] = 1;
    for(int i = 0; i < n; i++)
    {
        dp[i + 1] = (dp[i] + 1) % 2;
        dp[i + 3] = (dp[i] + 1) % 2;
    }
    std::cout << (dp[n] == 1 ? "SK\n" : "CY\n");
    return 0;
}