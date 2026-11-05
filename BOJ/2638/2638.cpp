#include <iostream>
#include <queue>
#include <cstring>
#define MAX 102
typedef std::pair<int, int> POS;
int n, m, map[MAX][MAX], contact[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
void bfs(std::queue<POS> &air, std::queue<POS> &cheese)
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
            if(!map[nx][ny])
            {
                visited[nx][ny] = true;
                air.push({nx, ny});
            }
            else
            {
                contact[nx][ny]++;
                if(contact[nx][ny] >= 2)
                {
                    visited[nx][ny] = true;
                    cheese.push({nx, ny});
                }
            }
        }
    }
}
int simulate()
{
    int Time = 0;
    std::queue<POS> air, cheese;
    
    air.push({0, 0});
    visited[0][0] = true;
    while(!air.empty())
    {
        bfs(air, cheese);
        if(cheese.empty())
        {
            break;
        }
        while(!cheese.empty())
        {
            auto front = cheese.front();
            cheese.pop();
            air.push(front);
        }
        Time++;
    }
    return Time;
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
    std::cout << simulate() << '\n';
    return 0;
}