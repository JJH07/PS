#include <iostream>
#include <cstring>
#define MIN -1e8
int n, m, k, ans = 0;
int matrix[70][70];
int dp[71][71][71][36];
int solve(int i, int j, int rest, int count)
{
    if(i == n - 1 && (!count || j == m))
    {
        return (rest == 0 ? 0 : MIN);
    }
    if(j == m || !count)
    {
        return dp[i][j][rest][count] = solve(i + 1, 0, rest, m / 2);
    }
    int &ret = dp[i][j][rest][count];
    if(ret != -1)
    {
        return ret;
    }
    int temp = MIN, R = matrix[i][j] % k;
    R = R <= rest ? rest - R : k - (R - rest);
    temp = std::max(temp, matrix[i][j] + solve(i, j + 1, R, count - 1));
    ret = std::max(temp, solve(i, j + 1, rest, count));
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));

    std::cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << std::max(0, solve(0, 0, 0, m / 2)) << '\n';
    return 0;
}