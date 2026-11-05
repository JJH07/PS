#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 50
struct node{
    int x, y, c;
};
int n;
std::string map[MAX];
int visited[MAX][MAX];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::fill(visited[0], visited[0] + MAX * MAX, MAX * MAX);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> map[i];
    }
    std::queue<node> q;
    q.push({0, 0, 0});
    visited[0][0] = 0;
    while(!q.empty())
    {
        auto [x, y, c] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx < 0 || ny < 0 || nx >= n || ny >= n)
            {
                continue;
            }
            int nc = (map[nx][ny] == '0' ? 1 : 0) + c;
            if(visited[nx][ny] > nc)
            {
                q.push({nx, ny, nc});
                visited[nx][ny] = nc;
            }
        }
    }
    std::cout << visited[n - 1][n - 1] << '\n';
    return 0;
}