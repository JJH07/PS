#include <iostream>
#define MAX 1000001
#define MOD 1000000009
typedef long long ll;
ll dp[MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i < MAX; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
    }
    int T;
    std::cin >> T;
    while(T--)
    {
        int n;
        std::cin >> n;
        std::cout << dp[n] << '\n';
    }
    return 0;
}