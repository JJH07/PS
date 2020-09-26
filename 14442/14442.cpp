#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>

const int INF = 1e9;
struct qn{
    int x, y, k;
};
int n, m, k;
int dist[1001][1001][11];
std::string map[1001];  
std::queue<qn> q;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::fill(dist[0][0], dist[0][0] + 1001 * 1001 * 11, INF);

    std::cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        std::cin >> map[i];
    }
    if(map[0][0] == '1')
    {
        k--;
    }
    q.push({0, 0, k});
    int ans = INF;
    dist[0][0][k] = 1;
    while(!q.empty())
    {
        auto [x, y, k] = q.front();
        q.pop();
        if(x == n - 1 && y == m - 1)
        {
            ans = std::min(ans, dist[x][y][k]);
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || dist[nx][ny][k] <= dist[x][y][k] + 1)
            {
                continue;
            }
            if(k == 0 && map[nx][ny] == '1')
            {
                continue;
            }
            dist[nx][ny][k] = dist[x][y][k] + 1;
            if(map[nx][ny] == '0')
            {
                q.push({nx, ny, k});
            }
            else
            {
                dist[nx][ny][k - 1] = dist[x][y][k] + 1;
                q.push({nx, ny, k - 1});
            }   
        }
    }
    std::cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}