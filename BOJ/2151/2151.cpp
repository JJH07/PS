#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
const int INF = 1e6;
struct node{
    int x, y, way;
    node(int X, int Y, int W) : x(X), y(Y), way(W){}
};
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::string map[51];
    std::vector<std::pair<int, int>> door;
    std::queue<node> q;
    int visited[50][50][4];
    
    std::fill(visited[0][0], visited[0][0] + 50 * 50 * 4, INF);
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> map[i];
        for(int j = 0; j < n; j++)
        {
            if(map[i][j] == '#')
            {
                door.push_back(std::make_pair(i, j));
            }
        }
    }
    for(int i = 0; i < 4; i++)
    {
        q.push(node(door[0].first, door[0].second, i));
        visited[door[0].first][door[0].second][i] = 0;
    }
    while(!q.empty())
    {
        auto [x, y, d] = q.front();
        q.pop();
        int keep = visited[x][y][d];
        while(1)
        {
            x += dx[d];
            y += dy[d];
            if(x < 0 || y < 0 || x >= n || y >= n || map[x][y] == '*')
            {
                break;
            }
            if(map[x][y] == '#')
            {
                if(visited[x][y][d] > keep)
                {
                    visited[x][y][d] = keep;
                    visited[x][y][d] = std::min(visited[x][y][d], keep);
                }
            }
            if(map[x][y] == '!')
            {
                for(int i = -1; i <= 1; i += 2)
                {
                    int nd = (4 + d + i) % 4;
                    if(visited[x][y][nd] > keep + 1)
                    {
                        visited[x][y][nd] = keep + 1;
                        q.push(node(x, y, nd));
                    }
                }
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < 4; i++)
    {
        ans = std::min(ans, visited[door[1].first][door[1].second][i]);
    }
    std::cout << ans << '\n';
    return 0;
}