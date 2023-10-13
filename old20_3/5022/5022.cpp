#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

const int INF = 1e9;

int n, m;
int trace[101][101][2];
bool visited[101][101];
std::queue<std::pair<int, int>> keep;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int bfs(std::pair<int, int> s, std::pair<int, int> e)
{
    std::queue<std::pair<int, std::pair<int, int>>> q;
    std::memset(visited, 0, sizeof(visited));
    std::memset(trace, -1, sizeof(trace));
    while(!keep.empty())
    {
        auto [x, y] = keep.front();
        keep.pop();
        visited[x][y] = 1;
    }
    q.push({0, s});
    visited[s.first][s.second] = 1;
    int ans = -INF;
    while(!q.empty())
    {
        auto[dist, pos] = q.front();
        q.pop();
        if(pos == e)
        {
            ans = dist;
            break;
        }
        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + pos.first;
            int ny = dy[i] + pos.second;
            if(nx < 0 || ny < 0 || nx > n || ny > m || visited[nx][ny])
            {
                continue;
            }
            q.push({dist + 1, {nx, ny}});
            visited[nx][ny] = 1;
            trace[nx][ny][0] = pos.first;
            trace[nx][ny][1] = pos.second;
        }
    }
    if(ans == -INF)
    {
        return ans;
    }
    int tx = e.first;
    int ty = e.second;
    while(tx > -1 && ty > -1)
    {
        keep.push({tx, ty});
        int nx = trace[tx][ty][0];
        int ny = trace[tx][ty][1];
        tx = nx;
        ty = ny;
    }
    return ans;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::pair<int, int> pts[4];
    std::cin >> n >> m;
    for(int i = 0; i < 4; i++)
    {
        std::cin >> pts[i].first >> pts[i].second;
    }

    keep.push(pts[2]);
    keep.push(pts[3]);
    int ans = bfs(pts[0], pts[1]);
    ans += bfs(pts[2], pts[3]);
    
    while(!keep.empty())
    {
        keep.pop();
    }
    keep.push(pts[0]);
    keep.push(pts[1]);
    int ans2 = bfs(pts[2], pts[3]);
    ans2 += bfs(pts[0], pts[1]);
    
    int ret = std::min((ans > 0 ? ans : INF), (ans2 > 0 ? ans2 : INF));
    if(ret != INF)
    {
        std::cout << ret << '\n';
    }
    else
    {
        std::cout << "IMPOSSIBLE\n";
    }
    return 0;
}