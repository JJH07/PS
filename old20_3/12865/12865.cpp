#include <iostream>
#include <algorithm>
#include <cstring>

struct backpack{
    int w;
    int v;
};
int n, k, dp[101][100001];
backpack bp[101];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> bp[i].w >> bp[i].v;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int W = 1; W <= k; W++)
        {
            dp[i][W] = (W >= bp[i].w) ? (std::max(dp[i - 1][W], bp[i].v + dp[i - 1][W - bp[i].w])) : (dp[i - 1][W]);
        }
    }
    std::cout << dp[n][k] << '\n';
    return 0;
}