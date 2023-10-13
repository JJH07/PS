#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 101
typedef std::pair<int, int> pii;
int n, m, k, map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::queue<pii> q;
    std::vector<int> list;
    std::cin >> n >> m >> k;
    while(k--)
    {
        int r, c;
        std::cin >> r >> c;
        map[r][c]++;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(visited[i][j] || !map[i][j])
            {
                continue;
            }
            q.push({i, j});
            visited[i][j] = true;
            list.push_back(1);
            while(!q.empty())
            {
                auto [x, y] = q.front();
                q.pop();
                for(int di = 0; di < 4; di++)
                {
                    int nx = dx[di] + x;
                    int ny = dy[di] + y;
                    if(nx <= 0 || ny <= 0 || nx > n || ny > m || map[nx][ny] == 0 || visited[nx][ny])
                    {
                        continue;
                    }
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    list.back()++;
                }
            }
        }
    }
    std::cout << *std::max_element(list.begin(), list.end()) << '\n';
    return 0;
}