#include <iostream>
#include <queue>
#include <cstring>

struct nd{
    int x, y;
    nd(int X, int Y) : x(X), y(Y) {}
};
int n, map[101][101];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool dfs(int d)
{
    std::queue<nd> q;
    bool visited[n + 1][n + 1];
    int s = map[1][1] >= d ? map[1][1] - d : 0;
    int e = map[1][1] + d > 200 ? 200 - d : map[1][1];
    for(int i = s; i <= e; i++)
    {
        std::memset(visited, 0, sizeof(visited));
        visited[1][1] = 1;
        q.push(nd(1, 1));
        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            if(x == n && y == n)
            {
                return true;
            }
            for(int di = 0; di < 4; di++)
            {
                int nx = dx[di] + x;
                int ny = dy[di] + y;
                if(nx < 1 || ny < 1 || nx > n || ny > n || visited[nx][ny])
                {
                    continue;
                }
                if(map[nx][ny] >= i && map[nx][ny] <= i + d)
                {
                    visited[nx][ny] = 1;
                    q.push(nd(nx, ny));
                }
            }
        }
    }
    return false;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cin >> map[i][j];
        }
    }
    int lo = 0, hi = 200;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(dfs(mid))
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    std::cout << lo << '\n';
    return 0;
}