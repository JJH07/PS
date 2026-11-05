#include <bits/stdc++.h>
#define MAX 31
typedef long long ll;
ll dp[MAX][MAX];

ll solve(int n, int k)
{
    if(k == 0 || n == k)
    {
        return 1;
    }
    ll &ret = dp[n][k];
    if(ret != -1)
    {
        return ret;
    }
    return ret = solve(n - 1, k - 1) + solve(n - 1, k);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));

    int n, k;
    std::cin >> n >> k;
    ll ans = solve(n - 1, k - 1);
    std::cout << ans << '\n';
    return 0;
}