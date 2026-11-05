#include <iostream>
#include <queue>
#define MAX 201
struct node{
    int x, y, c;
};
int n, r1, c1, r2, c2;
bool visited[MAX][MAX];
int dx[6] = {-2, -2, 0, 0, 2, 2}, dy[6] = {-1, 1, -2, 2, -1, 1};
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::queue<node> q;
    int ans = -1;
    std::cin >> n >> r1 >> c1 >> r2 >> c2;

    q.push({r1, c1, 0});
    visited[r1][c1] = true;

    while(!q.empty())
    {
        auto [x, y, c] = q.front();
        q.pop();
        if(x == r2 && y == c2)
        {
            ans = c;
            break;
        }
        for(int i = 0; i < 6; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny])
            {
                continue;
            }
            q.push({nx, ny, c + 1});
            visited[nx][ny] = true;
        }
    }
    std::cout << ans << '\n';
    return 0;
}