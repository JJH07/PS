#include <iostream>
#define MAX 10001
double dp[MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::fixed;
    std::cout.precision(3);

    int n;
    double ans = 0;
    std::cin >> n;

    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        double number;
        std::cin >> number;
        dp[i] = std::max(number, dp[i - 1] * number);
        ans = std::max(ans, dp[i]);
    }
    std::cout << ans << '\n';
    return 0;
}