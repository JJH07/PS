#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
int n, list[101][101], dp[101][101];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        list[x][y] = list[y][x] = 1;
    }
    for(int y = 1; y <= 100; y++)
    {
        for(int x = y - 1; x >= 1; x--)
        {
            int ans = 0;
            for(int k = x; k <= y; k++)
            {
                ans = std::max(ans, dp[x][k - 1] + dp[k + 1][y - 1] + list[k][y]);
            }
            dp[x][y] = ans;
        }
    }
    std::cout << dp[1][100] << '\n';
    return 0;
}