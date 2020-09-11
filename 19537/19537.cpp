#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

struct Unit{
    int m, t, x, y;
};
struct pq_n{
    int d, x, y;
    bool operator<(const pq_n &rhs) const{
        return d < rhs.d;
    }
};
int N, H, W, M, K;
int shape[500][500], dist[500][500], u_map[500][500];
std::vector<Unit> units;
std::priority_queue<pq_n> pq;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> H >> W;
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            std::cin >> shape[i][j];
        }
    }
    int type[N + 1];
    for(int i = 1; i <= N; i++)
    {
        std::cin >> type[i];
    }
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            shape[i][j] = type[shape[i][j]];
        }
    }
    std::cin >> M;
    units.resize(M + 1);
    for(int i = 1; i <= M; i++)
    {
        int m, t, a, b;
        std::cin >> m >> t >> a >> b;
        units[i] = {m, t, a, b};
        u_map[a][b] = i;
    }
    std::cin >> K;
    while(K--)
    {
        int u, a, b;
        std::cin >> u >> a >> b;
        if(u_map[a][b] > 0 || shape[a][b] == -1)
        {
            continue;
        }
        Unit &s = units[u];
        std::memset(dist, -1, sizeof(dist));

        u_map[s.x][s.y] = 0;
        dist[s.x][s.y] = s.m;
        for(int di = 0; di < 4; di++)
        {
            int nx = dx[di] + s.x;
            int ny = dy[di] + s.y;
            if(nx < 0 || ny < 0 || nx >= H || ny >= W || shape[nx][ny] == -1)
            {
                continue;
            }
            if(u_map[nx][ny] == 0 || units[u_map[nx][ny]].t == s.t)
            {
                int nd = s.m - shape[nx][ny];
                if(nd >= 0)
                {
                    pq.push({nd, nx, ny});
                    dist[nx][ny] = nd;
                }
            }
        }
        while(!pq.empty())
        {
            auto [d, x, y] = pq.top();
            pq.pop();
            if(dist[x][y] > d)
            {
                continue;
            }
            bool FLAG = false;
            for(int di = 0; di < 4; di++)
            {
                int nx = dx[di] + x;
                int ny = dy[di] + y;
                if(nx < 0 || ny < 0 || nx >= H || ny >= W || shape[nx][ny] == -1 || u_map[nx][ny] == 0)
                {
                    continue;
                }
                if(units[u_map[nx][ny]].t != s.t)
                {
                    FLAG = true;
                    break;
                }
            }
            if(FLAG)
            {
                continue;
            }
            for(int di = 0; di < 4; di++)
            {
                int nx = dx[di] + x;
                int ny = dy[di] + y;
                if(nx < 0 || ny < 0 || nx >= H || ny >= W || shape[nx][ny] == -1)
                {
                    continue;
                }
                if(u_map[nx][ny] == 0 || units[u_map[nx][ny]].t == s.t)
                {
                    int nd = d - shape[nx][ny];
                    if(nd > dist[nx][ny])
                    {
                        pq.push({nd, nx, ny});
                        dist[nx][ny] = nd;
                    }
                }
            }
        }
        if(dist[a][b] != -1)
        {
            s.x = a;
            s.y = b;
        }
        u_map[s.x][s.y] = u;
    }

    for(int i = 1; i <= M; i++)
    {
        std::cout << units[i].x << ' ' << units[i].y << '\n';
    }
    return 0;
}