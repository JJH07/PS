#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

int n, m;
int visited[1000][1000];
std::string map[1000];
std::vector<int> section(1);
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int get_number(int i, int j)
{
    if(map[i][j] == '0')
    {
        return 0;
    }
    int ret = 1;
    std::vector<int> list;
    for(int di = 0; di < 4; di++)
    {
        int nx = dx[di] + i;
        int ny = dy[di] + j;
        if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] == 0)
        {
            continue;
        }
        list.push_back(visited[nx][ny]);
    }
    std::sort(list.begin(), list.end());
    list.erase(std::unique(list.begin(), list.end()), list.end());
    for(auto x : list)
    {
        ret += section[x];
    }
    return ret % 10;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::memset(visited, 0, sizeof(visited));

    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        std::cin >> map[i];
    }
    
    int section_idx = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] == '0' && visited[i][j] == 0)
            {
                section_idx++;

                std::queue<std::pair<int, int>> q;
                int q_sz = 0;
                q.push({i, j});
                visited[i][j] = section_idx;
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
                        visited[nx][ny] = section_idx;
                    }
                }
                section.push_back(q_sz);
            }
        }
    }
    std::cout << "======================\n";
    for(auto x : section)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cout << visited[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "======================\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cout << get_number(i, j);
        }
        std::cout << '\n';
    }
    return 0;
}