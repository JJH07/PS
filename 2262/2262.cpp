#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

int n, dp[256][256], minimum[256][256];
int solve(int s, int e)
{
    if(s == e)
    {
        return 0;
    }
    int &ret = dp[s][e];
    if(dp[s][e] != -1)
    {
        return ret;
    }
    ret = INT_MAX;
    for(int i = s; i < e; i++)
    {   
        ret = std::min(ret, solve(s, i) + solve(i + 1, e) + abs(minimum[s][i] - minimum[i + 1][e]));
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::fill(dp[0], dp[0] + 256 * 256, -1);

    std::cin >> n;
    std::vector<int> list(n);
    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(i == j)
            {
                minimum[i][j] = list[i];
            }
            else
            {
                minimum[i][j] = std::min(minimum[i][j - 1], list[j]);
            }
        }
    }
    std::cout << solve(0, n - 1) << '\n';
    return 0;
}