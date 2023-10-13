#include <iostream>
#include <string>
#define INF 10001
std::string map[10];
int bit[10], dx[5] = {0, 0, 0, -1, 1}, dy[5] = {0, -1, 1, 0, 0};
int dfs(int x, int before, int now)
{
    if(x == 10)
    {
        return before > 0 ? INF : 0;
    }
    int next = bit[x + 1], Pressed = 0;
    for(int y = 0; y < 10; y++)
    {
        if((before & (1 << y)) == 0)
        {
            continue;
        }
        ++Pressed;
        for(int di = 0; di < 5; di++)
        {
            int nx = dx[di] + x;
            int ny = dy[di] + y;
            if(nx < 0 || ny < 0 || nx >= 10 || ny >= 10)
            {
                continue;
            }
            if(0 <= di && di <= 2)
            {
                now += ((now & (1 << ny)) == 0 ? (1 << ny) : -(1 << ny));
            }
            else if(di == 3)
            {
                before += ((before & (1 << ny)) == 0 ? (1 << ny) : -(1 << ny));
            }
            else
            {
                next += ((next & (1 << ny)) == 0 ? (1 << ny) : -(1 << ny));
            }
        }
    }
    return Pressed + dfs(x + 1, now, next);
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    for(int i = 0; i < 10; i++)
    {
        std::cin >> map[i];
        for(int j = 0; j < 10; j++)
        {
            bit[i] += map[i][j] == 'O' ? (1 << j) : 0;
        }
    }
    int ans = INF;
    for(int before = 0; before < (1 << 10); before++)
    {
        ans = std::min(ans, dfs(0, before, bit[0]));
    }
    std::cout << ans << '\n';
    return 0;
}