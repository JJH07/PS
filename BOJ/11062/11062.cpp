#include <iostream>
#include <vector>
#include <cstring>
#define MAX 1001
int n, list[MAX], dp[MAX][MAX];
int solve(int s, int e, bool turn)
{
    if(s > e)
    {
        return 0;
    }
    int &ret = dp[s][e];
    if(ret != -1)
    {
        return ret;
    }
    if(turn)
    {
        ret = std::max(list[s] + solve(s + 1, e, !turn), list[e] + solve(s, e - 1, !turn));
    }
    else
    {
        ret = std::min(solve(s + 1, e, !turn), solve(s, e - 1, !turn));
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        std::memset(dp, -1, sizeof(dp));
        std::cin >> n;
        for(int i = 0; i < n; i++)
        {
            std::cin >> list[i];
        }
        std::cout << solve(0, n - 1, true) << '\n';
    }
    return 0;
}