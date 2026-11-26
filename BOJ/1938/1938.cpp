// Copyright © 2020 진준호. All rights reserved.

#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

struct State
{
    int row, col, dir, dist;
};

bool canMove(const std::vector<std::string> &grid, int row, int col, int dir)
{
    const int n = grid.size();
    for(int offset = -1; offset <= 1; offset++)
    {
        int r = row + (dir == 1 ? offset : 0);
        int c = col + (dir == 0 ? offset : 0);
        if(r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != '0')
        {
            return false;
        }
    }
    return true;
}

bool canRotate(const std::vector<std::string> &grid, int row, int col)
{
    const int n = grid.size();
    if(row < 1 || col < 1 || row + 1 >= n || col + 1 >= n)
    {
        return false;
    }
    for(int r = row - 1; r <= row + 1; r++)
    {
        for(int c = col - 1; c <= col + 1; c++)
        {
            if(grid[r][c] != '0')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::string> grid(n);
    std::vector<std::pair<int, int>> start, target;
    for(int row = 0; row < n; row++)
    {
        std::cin >> grid[row];
        for(int col = 0; col < n; col++)
        {
            if(grid[row][col] == 'B')
            {
                start.push_back({row, col});
                grid[row][col] = '0';
            }
            else if(grid[row][col] == 'E')
            {
                target.push_back({row, col});
                grid[row][col] = '0';
            }
        }
    }
    // 0: horizontal, 1: vertical.
    const int startDir = start[0].first != start[1].first;
    const int targetDir = target[0].first != target[1].first;
    bool visited[50][50][2]{};
    std::queue<State> q;
    q.push({start[1].first, start[1].second, startDir, 0});
    visited[start[1].first][start[1].second][startDir] = true;
    constexpr int dr[4] = {1, 0, -1, 0};
    constexpr int dc[4] = {0, 1, 0, -1};
    int answer = 0;
    while(!q.empty())
    {
        const auto current = q.front();
        q.pop();
        auto [row, col, dir, dist] = current;
        if(row == target[1].first && col == target[1].second && dir == targetDir)
        {
            answer = dist;
            break;
        }
        const int nextDir = 1 - dir;
        if(!visited[row][col][nextDir] && canRotate(grid, row, col))
        {
            visited[row][col][nextDir] = true;
            q.push({row, col, nextDir, dist + 1});
        }
        for(int i = 0; i < 4; i++)
        {
            int nextRow = row + dr[i], nextCol = col + dc[i];
            if(!canMove(grid, nextRow, nextCol, dir) || visited[nextRow][nextCol][dir])
            {
                continue;
            }
            visited[nextRow][nextCol][dir] = true;
            q.push({nextRow, nextCol, dir, dist + 1});
        }
    }
    std::cout << answer << '\n';
    return 0;
}
