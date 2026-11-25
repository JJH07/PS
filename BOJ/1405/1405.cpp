#include <iostream>

constexpr int dr[4] = {0, 0, 1, -1};
constexpr int dc[4] = {1, -1, 0, 0};
int n;
bool visited[30][30];
double prob[4], answer;

void dfs(int row, int col, int steps, double chance)
{
    visited[row][col] = true;
    if(steps == n)
    {
        answer += chance;
        visited[row][col] = false;
        return;
    }
    for(int dir = 0; dir < 4; dir++)
    {
        if(prob[dir] == 0.0)
        {
            continue;
        }
        const int nextRow = row + dr[dir];
        const int nextCol = col + dc[dir];
        const double nextChance = prob[dir] * chance;
        if(!visited[nextRow][nextCol])
        {
            dfs(nextRow, nextCol, steps + 1, nextChance);
        }
    }
    visited[row][col] = false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.precision(10);

    std::cin >> n;
    for(int dir = 0; dir < 4; dir++)
    {
        double percent;
        std::cin >> percent;
        prob[dir] = percent / 100.0;
    }
    dfs(14, 14, 0, 1.0);
    std::cout << answer << '\n';
    return 0;
}
