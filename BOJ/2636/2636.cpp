#include <iostream>
#include <queue>
#include <cstring>
typedef std::pair<int, int> PII;
struct node{
    int x, y;
};
int n, m, map[102][102];
bool visited[102][102];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool Air(std::queue<node> &air, std::queue<node> &cheese)
{
    while(!air.empty())
    {
        auto [x, y] = air.front();
        air.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx < 0 || ny < 0 || nx > n || ny > m || visited[nx][ny])
            {
                continue;
            }
            if(map[nx][ny])
            {
                cheese.push({nx, ny});
            }
            else
            {
                air.push({nx, ny});
            }
            visited[nx][ny] = 1;
        }
    }
    return cheese.empty();
}
void simulate()
{
    std::queue<node> air, cheese;
    int ans = 0, step = 1;
    air.push({0, 0});
    visited[0][0] = 1;
    while(!air.empty())
    {
        if(Air(air, cheese))
        {
            break;
        }
        ans = cheese.size();
        while(!cheese.empty())
        {
            auto front = cheese.front();
            air.push(front);
            cheese.pop();
        }
        step++;
    }
    std::cout << step - 1 << '\n' << ans << '\n';
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            std::cin >> map[i][j];
        }
    }
    simulate();
    return 0;
}