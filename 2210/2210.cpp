#include <iostream>
#include <set>
int map[5][5];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
std::set<int> ans;
void dfs(int x, int y, int count, int number)
{
    if(count == 6)
    {
        ans.insert(number);
        return ;
    }
    for(int i = 0; i < 4; i++)
    {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
        {
            continue;
        }
        dfs(nx, ny, count + 1, number * 10 + map[nx][ny]);
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            std::cin >> map[i][j];
        }
    }
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            dfs(i, j, 1, map[i][j]);
        }
    }
    std::cout << ans.size() << '\n';
    return 0;
}