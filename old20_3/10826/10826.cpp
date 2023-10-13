#include <iostream>
#include <vector>
#define MAX 10001
#define MOD (long long)1e12
typedef long long ll;
std::vector<ll> dp[MAX];
ll Get(int i, int j)
{
    if(dp[i].size() <= j)
    {
        return 0;
    }
    return dp[i][j];
}
int main()
{
    dp[0].push_back(0);
    dp[1].push_back(1);
    for(int i = 2; i < MAX; i++)
    {
        int len = std::max(dp[i - 1].size(), dp[i - 2].size());
        ll up = 0;
        for(int j = 0; j < len; j++)
        {
            ll a = Get(i - 1, j);
            ll b = Get(i - 2, j);
            ll M = (a + b + up) / MOD;
            ll N = (a + b + up) % MOD;
            dp[i].push_back(N);
            up = M;
        }
        if(up > 0)
        {
            dp[i].push_back(up);
        }
    }
    int n;
    scanf("%d", &n);
    for(auto idx = dp[n].rbegin(); idx != dp[n].rend(); idx++)
    {
        if(idx == dp[n].rbegin())
        {
            printf("%lld", *idx);
        }
        else
        {
            printf("%012lld", *idx);
        }
    }
    return 0;
}