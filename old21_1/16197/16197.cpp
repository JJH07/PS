#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 20
typedef std::pair<int, int> pii;
typedef std::vector<pii> vctr;
struct node{
    vctr coin;
    int step;
};
int n, m;
std::string map[20];
vctr coin;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int simulate()
{
    std::queue<node> q;
    bool visited[MAX][MAX][MAX][MAX];

    std::memset(visited, 0, sizeof(visited));
    
    q.push({coin, 0});
    visited[coin[0].first][coin[0].second][coin[1].first][coin[1].second] = true;
    visited[coin[1].first][coin[1].second][coin[0].first][coin[0].second] = true;
    while(!q.empty())
    {
        auto [Coin, Step] = q.front();
        q.pop();
        if(Step > 10)
        {
            break;
        }
        for(int di = 0; di < 4; di++)
        {
            vctr nCoin(2);
            int dropped = 0;
            for(int ci = 0; ci < 2; ci++)
            {
                int nx = Coin[ci].first + dx[di];
                int ny = Coin[ci].second + dy[di];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                {
                    dropped++;
                }
                else
                {
                    nCoin[ci] = (map[nx][ny] == '#' ? Coin[ci] : std::make_pair(nx, ny));
                }
            }
            if(dropped == 2)
            {
                continue;
            }
            else if(dropped == 1)
            {
                return Step <= 9 ? Step + 1 : -1;
            }
            if(visited[nCoin[0].first][nCoin[0].second][nCoin[1].first][nCoin[1].second])
            {
                continue;
            }
            visited[nCoin[0].first][nCoin[0].second][nCoin[1].first][nCoin[1].second] = true;
            visited[nCoin[1].first][nCoin[1].second][nCoin[0].first][nCoin[0].second] = true;
            q.push({nCoin, Step + 1});
        }
    }
    return -1;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        std::cin >> map[i];
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] == 'o')
            {
                map[i][j] = '.';
                coin.push_back({i, j});
            }
        }
    }
    std::cout << simulate() << '\n';
    return 0;
}