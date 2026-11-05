#include <bits/stdc++.h>
#define MAX 5001
typedef long long ll;
const ll MOD = 1e9 + 7;
ll dp[5001];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    dp[1] = dp[0] = 1;
    for(int i = 2; i <= MAX / 2; i++)
    {
        for(int j = 0; j < i; j++)
        {
            dp[i] = (dp[i - j - 1] * dp[j] + dp[i]) % MOD;
        }
    }
    int tc;
    std::cin >> tc;
    while(tc--)
    {
        int L;
        std::cin >> L;
        if(L % 2)
        {
            std::cout << "0\n";
        }
        else
        {
            std::cout << dp[L / 2] << '\n';
        }
    }
    return 0;
}