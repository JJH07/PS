#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define MAX 500
int n, m, b, map[MAX][MAX];
int solve(int height)
{
    int blocks = 0, ret = 0;
    for(int x = 0; x < n; x++)
    {
        for(int y = 0; y < m; y++)
        {
            ret += (map[x][y] < height ? height - map[x][y] :  2 * (map[x][y] - height));
            blocks += height - map[x][y];
        }
    }
    return blocks <= b ? ret : INT_MAX;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m >> b;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cin >> map[i][j];
        }
    }
    int ans = INT_MAX, height;
    for(int i = 0; i <= 256; i++)
    {
        int time = solve(i);
        if(ans >= time)
        {
            ans = time;
            height = i;
        }
    }
    std::cout << ans << ' ' << height << '\n';
    return 0;
}