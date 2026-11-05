#include <bits/stdc++.h>
#define MAX 101
int dp[MAX][MAX];
int solve(int a, int b)
{
    int &ret = dp[a][b];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    for(int i = 1; i <= b - 1; i++)
    {
        if(!solve(i, b - i))
        {
            return ret = 1;
        }
    }
    for(int i = 1; i <= a - 1; i++)
    {
        if(!solve(a - i, i))
        {
            return ret = 1;
        }
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    int n, m;
    std::cin >> n >> m;
    std::cout << (solve(n, m) ? "A\n" : "B\n");
    return 0;
}