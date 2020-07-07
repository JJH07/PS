#include <iostream>
#include <cstring>
#include <vector>
struct fish
{
    int x;
    int y;
    int way;
};
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1}, dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1}, eat;
void dfs(int ans, std::vector<fish> f, std::vector<int> dead, std::vector<std::vector<int>> map)
{
    eat = std::max(eat, ans);
    for(int i = 1; i <= 16; i++)
    {
        if(dead[i])
        {
            continue;
        }
        for(int d = 0; d < 8; d++)
        {
            int di = f[i].way + d;
            if(di > 8)
            {
                di -= 8;
            }
            int nx = dx[di] + f[i].x;
            int ny = dy[di] + f[i].y;
            if(nx >= 1 && ny >= 1 && nx <= 4 && ny <= 4 && map[nx][ny] != -1)
            {
                f[i].way = di;
                int swap_idx = map[nx][ny];
                if(swap_idx == 0)
                {
                    std::swap(map[f[i].x][f[i].y], map[nx][ny]);
                    f[i].x = nx;
                    f[i].y = ny;
                }
                else
                {
                    std::swap(map[f[i].x][f[i].y], map[nx][ny]);
                    std::swap(f[i].x, f[swap_idx].x);
                    std::swap(f[i].y, f[swap_idx].y);
                }
                break;
            }
        }
    }

    int w = f[0].way;
    int x = f[0].x;
    int y = f[0].y;
    for(int i = 1; i < 4; i++)
    {
        int nx = x + dx[w] * i;
        int ny = y + dy[w] * i;
        if(nx < 1 || ny < 1 || nx > 4 || ny > 4)
        {
            break;
        }
        if(map[nx][ny] == 0)
        {
            continue;
        }
        int swap_idx = map[nx][ny];

        map[x][y] = 0;
        map[nx][ny] = -1;
        std::swap(f[0], f[swap_idx]);
        dead[swap_idx] = 1;

        dfs(ans + swap_idx, f, dead, map);

        dead[swap_idx] = 0;
        std::swap(f[0], f[swap_idx]);
        map[nx][ny] = swap_idx;
        map[x][y] = -1;
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<fish> f(17);
    std::vector<int> dead(17, 0);
    std::vector<std::vector<int>> map(5, std::vector<int>(5));
    for(int i = 1; i <= 4; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            int idx, w;
            std::cin >> idx >> w;
            f[idx] = {i, j, w};
            map[i][j] = idx;
        }
    }
    eat += map[1][1];
    dead[map[1][1]] = 1;
    f[0] = f[map[1][1]];
    map[1][1] = -1;

    dfs(eat, f, dead, map);
    std::cout << eat << '\n';
    return 0;
}