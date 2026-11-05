#include <iostream>
#include <cstring>
#include <queue>
#define MAX 64

int n, q, l, map[MAX][MAX];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
void rotate(int x, int y)
{
    int temp[l][l];
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < l; j++)
        {
            temp[i][j] = map[x + (l - j - 1)][y + i];
        }
    }
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < l; j++)
        {
            map[x + i][y + j] = temp[i][j];
        }
    }
}
void melt()
{
    int table[n][n];
    std::memset(table, 0, sizeof(table));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] == 0)
            {
                continue;
            }
            for(int di = 0; di < 4; di++)
            {
                int nx = i + dx[di];
                int ny = j + dy[di];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                {
                    continue;
                }
                if(map[nx][ny] > 0)
                {
                    table[i][j]++;
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] > 0 && table[i][j] < 3)
            {
                map[i][j]--;
            }
        }
    }
}
int dfs()
{
    int biggest = 0, tot = 0;
    bool visited[n][n];
    std::queue<std::pair<int, int>> q;
    std::memset(visited, 0, sizeof(visited));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            tot += map[i][j];
            if(map[i][j] > 0 && !visited[i][j])
            {
                int counting = 1;
                visited[i][j] = true;
                q.push({i, j});
                while(!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    for(int di = 0; di < 4; di++)
                    {
                        int nx = x + dx[di];
                        int ny = y + dy[di];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny])
                        {
                            continue;
                        }
                        if(map[nx][ny] > 0)
                        {
                            counting++;
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
                biggest = std::max(biggest, counting);
            }
        }
    }
    std::cout << tot << '\n';
    return biggest;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> q;
    n = (1 << n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cin >> map[i][j];
        }
    }
    for(int i = 0; i < q; i++)
    {
        std::cin >> l;
        l = (1 << l);
        for(int i = 0; i < n; i += l)
        {
            for(int j = 0; j < n; j += l)
            {
                rotate(i, j);
            }
        }
        melt();
    }
    std::cout << dfs() << '\n';
    return 0;
}