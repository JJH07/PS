#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 501
typedef std::pair<int, int> PII;
int n, m, paper[MAX][MAX];
bool visited[MAX][MAX];
std::vector<int> list;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::queue<PII> q;

    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cin >> paper[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!paper[i][j] || visited[i][j])
            {
                continue;
            }
            q.push({i, j});
            visited[i][j] = true;
            list.push_back(1);
            while(!q.empty())
            {
                auto [x, y] = q.front();
                q.pop();
                for(int di = 0; di < 4; di++)
                {
                    int nx = dx[di] + x;
                    int ny = dy[di] + y;
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || !paper[nx][ny] || visited[nx][ny])
                    {
                        continue;
                    }
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    list.back()++;
                }
            }
        }
    }
    std::cout << list.size() << '\n' << (list.size() == 0 ? 0 : *std::max_element(list.begin(), list.end())) << '\n';
    return 0;
}