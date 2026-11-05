#include <iostream>
#define MAX 81
typedef long long ll;
ll dp[MAX], ans[MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i < MAX; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    ans[1] = 4;
    ans[2] = 6;
    for(int i = 3; i < MAX; i++)
    {
        ans[i] = (dp[i] + dp[i - 1] + dp[i - 1] + dp[i - 2]) * 2;
    }
    int n;
    std::cin >> n;
    std::cout << ans[n] << '\n';
    return 0;
}