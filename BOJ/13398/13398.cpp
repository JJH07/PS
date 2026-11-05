#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
#define INF -100000000

int list[MAX], dp[MAX][2];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> list[i];
    }
    int ans = INF;
    dp[0][0] = dp[0][1] = INF;
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = std::max(dp[i - 1][0] + list[i], list[i]);
        dp[i][1] = std::max(dp[i - 1][1] + list[i], dp[i - 1][0]);
        ans = std::max({ans, dp[i][0], dp[i][1]});
    }
    std::cout << ans << '\n';
    return 0;
}