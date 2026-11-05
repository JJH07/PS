#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1000001
int dp[MAX], trace[MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(trace, -1, sizeof(trace));
    std::fill(dp, dp + MAX, MAX);
    dp[1] = 0;
    int n;
    std::cin >> n;
    for(int i = 1; i < n; i++)
    {
        if(dp[i + 1] > dp[i] + 1)
        {
            trace[i + 1] = i;
            dp[i + 1] = dp[i] + 1;
        }
        if(i * 2 <= n && dp[i * 2] > dp[i] + 1)
        {
            trace[i * 2] = i;
            dp[i * 2] = dp[i] + 1;
        }
        if(i * 3 <= n && dp[i * 3] > dp[i] + 1)
        {
            trace[i * 3] = i;
            dp[i * 3] = dp[i] + 1;
        }
    }
    std::cout << dp[n] << '\n';
    while(n >= 1)
    {
        std::cout << n << ' ';
        n = trace[n];
    }
    std::cout << '\n';
    return 0;
}