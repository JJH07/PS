#include <iostream>
#include <stack>
#include <cstring>

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int n, visited[30][30];
double w[4], ans;
void bfs(int x, int y, int count, double p)
{
    visited[x][y] = 1;
    if(count == n)
    {
        ans += p;
        visited[x][y] = 0;
        return ;
    }
    for(int i = 0; i < 4; i++)
    {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        double np = w[i] * p;
        if(!visited[nx][ny])
        {
            bfs(nx, ny, count + 1, np);
        }
    }
    visited[x][y] = 0;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.precision(10);

    std::cin >> n;
    for(int i = 0; i < 4; i++)
    {
        double tmp;
        std::cin >> tmp;
        w[i] = (double)tmp / 100.0;
    }
    bfs(14, 14, 0, 1.0);
    std::cout << ans << '\n';
    return 0;
}