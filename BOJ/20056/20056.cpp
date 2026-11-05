#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#define MAX 50
struct fireball{
    int direction, speed, mass;
    fireball(int D, int S, int M) : direction(D), speed(S), mass(M){}
};
int n, m, k;
std::queue<fireball> fb[MAX][MAX];
std::vector<fireball> map[MAX][MAX];
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
void cast()
{
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            map[i][j].clear();
        }
    }
    for(int x = 0; x < n; x++)
    {
        for(int y = 0; y < n; y++)
        {
            while(!fb[x][y].empty())
            {
                auto [dir, spd, mass] = fb[x][y].front();
                fb[x][y].pop();
                int nx = (n + ((x + (spd * dx[dir])) % n)) % n;
                int ny = (n + ((y + (spd * dy[dir])) % n)) % n;
                map[nx][ny].push_back(fireball(dir, spd, mass));
            }
        }
    }
    for(int x = 0; x < n; x++)
    {
        for(int y = 0; y < n; y++)
        {
            if(map[x][y].size() == 0)
            {
                continue;
            }
            if(map[x][y].size() == 1)
            {
                fb[x][y].push(map[x][y][0]);
            }
            else
            {
                int nmass = 0, nspd = 0, d_offset = 0;
                int odd = 0, even = 0;
                for(auto fb_t : map[x][y])
                {
                    nmass += fb_t.mass;
                    nspd += fb_t.speed;
                    fb_t.direction % 2 ? odd++ : even++;
                }
                nmass /= 5;
                nspd /= map[x][y].size();
                if(nmass == 0)
                {
                    continue;
                }
                if(odd > 0 && even > 0)
                {
                    d_offset = 1;
                }
                for(int i = d_offset; i < 8; i += 2)
                {
                    fb[x][y].push(fireball(i, nspd, nmass));
                }
            }
        }
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int x, y, mass, spd, dir;
        std::cin >> x >> y >> mass >> spd >> dir;
        fb[x - 1][y - 1].push(fireball(dir, spd, mass));
    }
    for(int i = 0; i < k; i++)
    {
        cast();
    }
    int ans = 0;
    for(int x = 0; x < n; x++)
    {
        for(int y = 0; y < n; y++)
        {
            while(!fb[x][y].empty())
            {
                auto [dir, spd, mass] = fb[x][y].front();
                fb[x][y].pop();
                ans += mass;
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}