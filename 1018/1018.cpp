#include <iostream>
#include <string>
typedef std::pair<int, int> pii;
int n, m;
std::string map[50];
int count(int sX, int sY)
{
    int WB = 0, BW = 0;
    for(int x = sX; x < sX + 8; x++)
    {
        for(int y = sY; y < sY + 8; y += 2)
        {
            if(x % 2)
            {
                map[x][y] == 'W' ? ++WB : ++BW;
            }
            else
            {
                map[x][y] == 'W' ? ++BW : ++WB;
            }
        }
        for(int y = sY + 1; y < sY + 8; y += 2)
        {
            if(x % 2)
            {
                map[x][y] == 'B' ? ++WB : ++BW;
            }
            else
            {
                map[x][y] == 'B' ? ++BW : ++WB;
            }
        }
    }
    return std::min(WB, BW);
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int ans = 2501;
    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        std::cin >> map[i];
    }
    for(int i = 0; i <= n - 8; i++)
    {
        for(int j = 0; j <= m - 8; j++)
        {
            ans = std::min(ans, count(i, j));
        }
    }
    std::cout << ans << '\n';
    return 0;
}