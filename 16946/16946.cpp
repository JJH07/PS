#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    int visited[1000][1000];
    std::string map[1000];
    std::vector<int> section(1, -1);

    std::memset(visited, 0, sizeof(visited));
    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        std::cin >> map[i];
    }
    
    int s_count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] == '0' && visited[i][j] == 0)
            {
                s_count++;
                std::queue<std::pair<int, int>> q;
                int q_sz = 0;
                q.push({i, j});
                visited[i][j] = s_count;
                while(!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    q_sz++;
                    for(int di = 0; di < 4; di++)
                    {
                        int nx = dx[di] + x;
                        int ny = dy[di] + y;
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny] == '1' || visited[nx][ny] > 0)
                        {
                            continue;
                        }
                        q.push({nx, ny});
                        visited[nx][ny] = s_count;
                    }
                }
                section.push_back(q_sz);
            }
        }
    }
    std::cout << "=====\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] == '0')
            {
                std::cout << '0';
            }
            else
            {
                int ret = 1;
                std::vector<int> t;
                for(int di = 0; di < 4; di++)
                {
                    int nx = dx[di] + i;
                    int ny = dy[di] + j;
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] == 0)
                    {
                        continue;
                    }
                    t.push_back(visited[nx][ny]);
                }
                t.erase(std::unique(t.begin(), t.end()), t.end());
                for(auto x : t)
                {
                    ret += section[x];
                }
                std::cout << ret % 10;
            }
        }
        std::cout << '\n';
    }
    return 0;
}