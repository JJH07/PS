#include <iostream>
#include <cstring>
#include <vector>
#define MAX 500

struct flow_t{
    int dx;
    int dy;
    int p;
};
int n, map[MAX][MAX], ans = 0;
std::vector<flow_t> table;
void init_flow_t()
{
    table.push_back({-2, 0, 2});
    table.push_back({-1, -1, 10});
    table.push_back({-1, 0, 7});
    table.push_back({-1, 1, 1});
    table.push_back({0, -2, 5});
    table.push_back({1, -1, 10});
    table.push_back({1, 0, 7});
    table.push_back({1, 1, 1});
    table.push_back({2, 0, 2});
    table.push_back({0, -1, -1});
}
void blow(int x, int y, int dir)
{
    if(map[x][y] == 0)
    {
        return ;
    }
    int sand = map[x][y];
    int rest = sand;
    map[x][y] = 0;
    for(auto [dx, dy, p] : table)
    {
        switch(dir){
            case 1 :
                std::swap(dx, dy);
                dx *= -1;
                break;
            case 2 :
                dy *= -1;
                break;
            case 3 :
                std::swap(dx, dy);
                break;
        }
        int nx = x + dx;
        int ny = y + dy;
        int np = (p != -1 ? (sand * p) / 100 : rest);
        if(nx <= 0 || ny <= 0 || nx > n || ny > n)
        {
            ans += np;
        }
        else
        {
            map[nx][ny] += np;
        }
        rest -= np;
    }
}
void tornado()
{
    int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
    int sx = n / 2 + 1;
    int sy = n / 2 + 1;
    int dir = 0, c = 1;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < i; k++)
            {
                sx = sx + dx[dir];
                sy = sy + dy[dir];
                blow(sx, sy, dir);
            }
            dir = (dir + 1) % 4; 
        }
    }
    for(int i = 0; i < n; i++)
    {
        sx = sx + dx[dir];
        sy = sy + dy[dir];
        blow(sx, sy, dir);
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    init_flow_t();
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cin >> map[i][j];
        }
    }
    tornado();
    std::cout << ans << '\n';
    return 0;
}