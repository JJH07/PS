#include <bits/stdc++.h>
bool dp[1001];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    dp[0] = true;
    dp[1] = false;
    dp[2] = true;
    dp[3] = false;
    int n;
    std::cin >> n;
    for(int i = 4; i <= n; i++)
    {
        if(!dp[i - 1] || !dp[i - 3] || !dp[i - 4])
        {
            dp[i] = true;
        }
        else
        {
            dp[i] = false;
        }
    }
    std::cout << (dp[n] ? "SK\n" : "CY\n");
    return 0;
}