#include <iostream>
#include <cstring>
#define MAX 10001
int r, c;
std::string map[MAX];
int dx[3] = {-1, 0, 1};
bool dfs(int x, int y)
{
    if(y == c - 1)
    {
        return true;
    }
    for(int i = 0; i < 3; i++)
    {
        int nx = x + dx[i];
        int ny = y + 1;
        if(nx < 0 || ny < 0 || nx >= r || ny >= c || map[nx][ny] == 'x')
        {
            continue;
        }
        map[nx][ny] = 'x';
        if(dfs(nx, ny))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> r >> c;
    for(int i = 0; i < r; i++)
    {
        std::cin >> map[i];
    }
    int ans = 0;
    for(int i = 0; i < r; i++)
    {
        if(dfs(i, 0))
        {
            ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}