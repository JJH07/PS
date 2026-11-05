#include <bits/stdc++.h>
typedef std::pair<int, int> pii;

const int MAX = 101;
int n, m, light[MAX][MAX], visited[MAX][MAX], dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
std::vector<pii> link[MAX][MAX];
std::queue<pii> q;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y, a, b;
        std::cin >> x >> y >> a >> b;
        link[x][y].push_back(std::make_pair(a, b));
    }

    int ans = 1;
    light[1][1] = 1;
    visited[1][1] = 1;
    q.push({1, 1});
    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for(auto [nx, ny] : link[x][y])
        {
            if(light[nx][ny])
            {
                continue;
            }
            ++ans;
            light[nx][ny] = 1;
            for(int di = 0; di < 4; di++)
            {
                int nnx = nx + dx[di];
                int nny = ny + dy[di];
                if(nnx > 0 && nnx <= n && nny > 0 && nny <= n && visited[nnx][nny])
                {
                    visited[nx][ny] = 1;
                    q.push(std::make_pair(nx, ny));
                    break;
                }
            }
        }
        for(int di = 0 ; di < 4; di++)
        {
            int nx = x + dx[di];
            int ny = y + dy[di];
            if(nx > 0 && nx <= n && ny > 0 && ny <= n && !visited[nx][ny] && light[nx][ny])
            {
                visited[nx][ny] = 1;
                q.push(std::make_pair(nx, ny));
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}