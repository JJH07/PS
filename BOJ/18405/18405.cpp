#include <bits/stdc++.h>


int map[201][201];
std::vector<std::tuple<int, int, int>> list;
std::queue<std::tuple<int, int, int>> q;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k, s, x, y;
    std::cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cin >> map[i][j];
            if(map[i][j])
            {
                list.push_back(std::make_tuple(map[i][j], i, j));
            }
        }
    }
    std::cin >> s >> x >> y;
    std::sort(list.begin(), list.end());
    for(auto t : list)
    {
        q.push(std::make_tuple(std::get<1>(t), std::get<2>(t), 0));
    }

    while(!q.empty())
    {
        auto [_x, _y, _d] = q.front();
        q.pop();

        if(_x == x && _y == y)
        {
            break;
        }
        if(_d < s)
        {
            for(int di = 0; di < 4; di++)
            {
                int nx = _x + dx[di];
                int ny = _y + dy[di];
                if(nx <= 0 || ny <= 0 || nx > n || ny > n || map[nx][ny])
                {
                    continue;
                }
                map[nx][ny] = map[_x][_y];
                q.push(std::make_tuple(nx, ny, _d + 1));
            }
        }
        // std::cout << _x << ' ' << _y << ' ' << _d << '\n';
    }
    std::cout << map[x][y] << '\n';
    return 0;
}