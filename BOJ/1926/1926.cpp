#include <iostream>
#include <queue>
#include <algorithm>
constexpr int MAX = 501;
typedef std::pair<int, int> PII;
int n, m, paper[MAX][MAX];
bool visited[MAX][MAX];

int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::queue<PII> q;
    int count = 0, maxArea = 0;

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
            count++;
            int area = 1;
            while(!q.empty())
            {
                auto [row, col] = q.front();
                q.pop();
                for(int di = 0; di < 4; di++)
                {
                    int nextRow = dr[di] + row;
                    int nextCol = dc[di] + col;
                    if(nextRow < 0 || nextCol < 0 || nextRow >= n || nextCol >= m || !paper[nextRow][nextCol] || visited[nextRow][nextCol])
                    {
                        continue;
                    }
                    q.push({nextRow, nextCol});
                    visited[nextRow][nextCol] = true;
                    area++;
                }
            }
            maxArea = std::max(maxArea, area);
        }
    }
    std::cout << count << '\n' << maxArea << '\n';
    return 0;
}
