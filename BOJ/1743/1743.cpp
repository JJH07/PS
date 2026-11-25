#include <iostream>
#include <queue>
#include <algorithm>
constexpr int MAX = 101;
typedef std::pair<int, int> pii;
int n, m, k, grid[MAX][MAX];
bool visited[MAX][MAX];
int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::queue<pii> q;
    int best = 0;
    std::cin >> n >> m >> k;
    while(k--)
    {
        int r, c;
        std::cin >> r >> c;
        grid[r][c]++;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(visited[i][j] || !grid[i][j])
            {
                continue;
            }
            q.push({i, j});
            visited[i][j] = true;
            int size = 1;
            while(!q.empty())
            {
                auto [row, col] = q.front();
                q.pop();
                for(int di = 0; di < 4; di++)
                {
                    int nextRow = dr[di] + row;
                    int nextCol = dc[di] + col;
                    if(nextRow <= 0 || nextCol <= 0 || nextRow > n || nextCol > m || grid[nextRow][nextCol] == 0 || visited[nextRow][nextCol])
                    {
                        continue;
                    }
                    q.push({nextRow, nextCol});
                    visited[nextRow][nextCol] = true;
                    size++;
                }
            }
            best = std::max(best, size);
        }
    }
    std::cout << best << '\n';
    return 0;
}
