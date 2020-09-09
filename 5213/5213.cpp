#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>

const int INF = 1e9;

int map[500][1000], tile_m[500][1000];
std::vector<int> trace, visited;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, tile_cnt = 1;
    std::queue<int> q;

    std::cin >> n;
    std::vector<int> link[n * n - n / 2 + 1];
    trace.resize(n * n - n / 2 + 1, 0);
    visited.resize(n * n - n / 2 + 1, 0);
    for(int i = 0; i < n; i++)
    {
        int res = i % 2;
        for(int j = res; j < (n - res) * 2; j += 2)
        {
            std::cin >> map[i][j] >> map[i][j + 1];
            tile_m[i][j] = tile_cnt;
            tile_m[i][j + 1] = tile_cnt++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n * 2; j++)
        {
            if(i < n - 1 && map[i][j] == map[i + 1][j])
            {
                link[tile_m[i][j]].push_back(tile_m[i + 1][j]);
                link[tile_m[i + 1][j]].push_back(tile_m[i][j]);
            }
            if(j < n * 2 - 1 && tile_m[i][j] != tile_m[i][j + 1] && map[i][j] == map[i][j + 1])
            {
                link[tile_m[i][j]].push_back(tile_m[i][j + 1]);
                link[tile_m[i][j + 1]].push_back(tile_m[i][j]);
            }
        }
    }
    q.push(1);
    visited[0] = 1;
    visited[1] = 1;
    int max_t = 1;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int next : link[now])
        {
            if(!visited[next])
            {
                visited[next] = 1;
                q.push(next);
                trace[next] = now;
                max_t = std::max(max_t, next);
            }
        }
    }
    std::vector<int> ans;
    while(max_t > 0)
    {
        ans.push_back(max_t);
        max_t = trace[max_t];
    }
    std::cout << ans.size() << '\n';
    for(auto x = ans.rbegin(); x !=  ans.rend(); x++)
    {
        std::cout << *x << ' ';
    }
    return 0;
}