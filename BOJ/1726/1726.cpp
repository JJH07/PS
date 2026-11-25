//  Copyright © 2019 진준호. All rights reserved.

#include <iostream>
#include <queue>

int n, m, grid[101][101], visited[101][101][5];
int dr[5] = {0, 0, 0, 1, -1}, dc[5] = {0, 1, -1, 0, 0};
struct State{
    int row;
    int col;
    int dir;
    int dist;
};
State current, target;
std::queue<State> q;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            std::cin >> grid[i][j];
        }
    }
    std::cin >> current.row >> current.col >> current.dir;
    std::cin >> target.row >> target.col >> target.dir;

    current.dist = 0;
    q.push(current);
    visited[current.row][current.col][current.dir] = 1;

    while(!q.empty())
    {
        current = q.front();
        q.pop();
        if(current.row == target.row && current.col == target.col && current.dir == target.dir)
        {
            std::cout << current.dist << '\n';
            break;
        }
        for(int step = 1; step <= 3; step++)
        {
            int nextRow = current.row + dr[current.dir] * step;
            int nextCol = current.col + dc[current.dir] * step;
            if(grid[nextRow][nextCol] == 1)
            {
                break;
            }
            if(nextRow <= 0 || nextCol <= 0 || nextRow > n || nextCol > m || visited[nextRow][nextCol][current.dir] == 1)
            {
                continue;
            }
            visited[nextRow][nextCol][current.dir] = 1;
            q.push({nextRow, nextCol, current.dir, current.dist + 1});
        }
        const int firstDir = current.dir <= 2 ? 3 : 1;
        for(int dir = firstDir; dir <= firstDir + 1; dir++)
        {
            if(visited[current.row][current.col][dir] == 0)
            {
                visited[current.row][current.col][dir] = 1;
                q.push({current.row, current.col, dir, current.dist + 1});
            }
        }
    }
    return 0;
}
