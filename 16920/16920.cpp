#include <bits/stdc++.h>
typedef std::pair<int, int> pii;
int n, m, p, player[10], castle[10], map[1001][1001];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
std::queue<pii> q[10];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n >> m >> p;
    for(int i = 1; i <= p; i++)
    {
        std::cin >> player[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            char c;
            std::cin >> c;
            if(c >= '1' && c <= '9')
            {
                map[i][j] = c - '0';
                q[map[i][j]].push(std::make_pair(i, j));
                castle[map[i][j]]++;
            }
            else if(c == '#')
            {
                map[i][j] = -1;
            }
        }
    }
    while(1)
    {
        int working = p;
        for(int i = 1; i <= p; i++)
        {
            if(q[i].empty())
            {
                --working;
            }
            for(int j = 0; j < player[i] && !q[i].empty(); j++)
            {
                int q_size = (int)q[i].size();
                while(q_size--)
                {
                    auto [x, y] = q[i].front();
                    q[i].pop();
                    
                    for(int di = 0; di < 4; di++)
                    {
                        int nx = dx[di] + x;
                        int ny = dy[di] + y;
                        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && map[nx][ny] == 0)
                        {
                            map[nx][ny] = i;
                            q[i].push(std::make_pair(nx, ny));
                            ++castle[i];
                        }
                    }
                }
            }
        }
        if(!working)
        {
            break;
        }
    }
    for(int i = 1; i <= p; i++)
    {
        std::cout << castle[i] << ' ';
    }
    return 0;
}