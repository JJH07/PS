#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

const int INF = 1e9;
struct qn{
    int x, y, d, k;
};
std::string map[1000];

int N, M, K;
int dist[11][1000][1000];
std::queue<qn> q;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::fill(dist[0][0], dist[0][0] + 11 * 1000 * 1000, INF);

    std::cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
    {
        std::cin >> map[i];
    }
    dist[K][0][0] = 1;
    q.push({0, 0, 1, K});
    while(!q.empty())
    {
        auto [x, y, d, k] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx < 0 || ny < 0 || nx >= N || ny >= M)
            {
                continue;
            }
            if(map[nx][ny] == '0' && dist[k][nx][ny] > d + 1)
            {
                dist[k][nx][ny] = d + 1;
                q.push({nx, ny, d + 1, k});
            }
            if(map[nx][ny] == '1' && k > 0)
            {
                int nd = (d % 2) ? d + 1 : d + 2;
                if(dist[k - 1][nx][ny] > nd)
                {
                    dist[k - 1][nx][ny] = nd;
                    q.push({nx, ny, nd, k - 1});
                }
            }
        }
    }
    
    int ans = INF;
    for(int i = 0; i <= K; i++)
    {
        ans = std::min(ans, dist[i][N - 1][M - 1]);
    }
    std::cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}