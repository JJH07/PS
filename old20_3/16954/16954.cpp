#include <iostream>
#include <string>
#include <cstring>
#include <queue>
struct pos{
    int x, y, t;
};
int dx[9] = {-1, 0, 1, 0, -1, -1, 1, 1, 0}, dy[9] = {0, -1, 0, 1, -1, 1, -1, 1, 0};
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string map[8];
    int visited[8][8];
    std::memset(visited, 0, sizeof(visited));
    for(int i = 0; i < 8; i++)
    {
        std::cin >> map[i];
    }
    std::queue<pos> q;
    bool FLAG = false;
    int tick = 1;

    q.push({7, 0, 1});
    visited[0][0] = 1;
    while(!q.empty())
    {
        auto [x, y, time] = q.front();
        q.pop();
        if(tick != time)
        {
            tick = time;
            for(int i = 7; i >= 0; i--)
            {
                for(int j = 0; j < 8; j++)
                {
                    if(map[i][j] == '.')
                    {
                        continue;
                    }
                    if(i == 7)
                    {
                        map[i][j] = '.';
                    }
                    else if(map[i + 1][j] == '.')
                    {
                        map[i + 1][j] = '#';
                        map[i][j] = '.';
                    }
                }
            }
        }
        if(map[x][y] == '#')
        {
            continue;
        }
        if(x == 0 && y == 7)
        {
            FLAG = true;
            break;
        }
        for(int i = 0; i < 9; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ntime = time + 1;
            if(nx < 0 || ny < 0 || nx >= 8 || ny >= 8 || map[nx][ny] == '#' || visited[nx][ny] >= ntime)
            {
                continue;
            }
            q.push({nx, ny, ntime});
            visited[nx][ny] = ntime;
        }
    }
    std::cout << FLAG << '\n';
    return 0;
}