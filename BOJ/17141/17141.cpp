#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 50
typedef std::pair<int, int> pii;
int n, m, map[MAX][MAX], table[10], ans = -1;
std::vector<pii> virus;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int bfs()
{
    std::queue<std::pair<pii, int>> q;
    bool visited[MAX][MAX];

    std::memset(visited, 0, sizeof(visited));

    for(int i = 0; i < m; i++)
    {
        pii &v = virus[table[i]];
        visited[v.first][v.second] = true;
        q.push({v, 0});
    }
    int ret = 0;
    while(!q.empty())
    {
        auto [Pos, Step] = q.front();
        q.pop();
        ret = Step;
        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + Pos.first;
            int ny = dy[i] + Pos.second;
            if(nx < 0 || ny < 0 || nx >= n || ny >= n || map[nx][ny] != 0 || visited[nx][ny])
            {
                continue;
            }
            visited[nx][ny] = true;
            q.push({{nx, ny}, Step + 1});
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] == 0 && !visited[i][j])
            {
                return -1;
            }
        }
    }
    return ret;
}
void permutation(int idx, int picked)
{
    if(picked == m)
    {
        int BFS = bfs();
        if(BFS > -1)
        {
            ans = ans == -1 ? BFS : std::min(ans, BFS);
        }
        return ;
    }
    int sz = (int)virus.size();
    for(int i = idx; i < sz; i++)
    {
        table[picked] = i;
        permutation(i + 1, picked + 1);
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cin >> map[i][j];
            if(map[i][j] == 2)
            {
                map[i][j] = 0;
                virus.push_back({i, j});
            }
        }
    }
    permutation(0, 0);
    std::cout << ans << '\n';
    return 0;
}