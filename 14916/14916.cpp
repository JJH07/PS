#include <bits/stdc++.h>
#define MAX 100015
#define INF 1e9
int dp[MAX];

int solve(int n)
{
    if(n == 0)
    {
        return 0;
    }
    else if(n < 0)
    {
        return INF;
    }
    int &ret = dp[n];
    if(ret != -1)
    {
        return ret;
    }
    ret = std::min(solve(n - 2), solve(n - 5));
    return ret == INF ? ret : ++ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));
    
    int n, ans;
    std::cin >> n;
    ans = solve(n);
    std::cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}