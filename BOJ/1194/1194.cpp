// Copyright © 2020 진준호. All rights reserved.

#include <iostream>
#include <queue>
#include <string>

struct State
{
    int row, col;
    int dist;
    int keyMask;
};

constexpr int dr[4] = {0, 1, 0, -1};
constexpr int dc[4] = {1, 0, -1, 0};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    bool visited[50][50][1 << 6]{};
    std::string maze[50];
    std::queue<State> queue;
    State start{};

    std::cin >> n >> m;
    for(int row = 0; row < n; row++)
    {
        std::cin >> maze[row];
        for(int col = 0; col < m; col++)
        {
            if(maze[row][col] == '0')
            {
                start.row = row;
                start.col = col;
            }
        }
    }

    visited[start.row][start.col][start.keyMask] = true;
    queue.push(start);
    int answer = -1;
    while(!queue.empty())
    {
        const State current = queue.front();
        queue.pop();
        if(maze[current.row][current.col] == '1')
        {
            answer = current.dist;
            break;
        }
        for(int i = 0; i < 4; i++)
        {
            const int row = current.row + dr[i];
            const int col = current.col + dc[i];
            if(row < 0 || row >= n || col < 0 || col >= m)
            {
                continue;
            }
            const char cell = maze[row][col];
            if(cell == '#')
            {
                continue;
            }
            int nextMask = current.keyMask;
            if(cell >= 'A' && cell <= 'F' && !(nextMask & (1 << (cell - 'A'))))
            {
                continue;
            }
            if(cell >= 'a' && cell <= 'f')
            {
                nextMask |= 1 << (cell - 'a');
            }
            if(visited[row][col][nextMask])
            {
                continue;
            }
            visited[row][col][nextMask] = true;
            queue.push({row, col, current.dist + 1, nextMask});
        }
    }
    std::cout << answer << '\n';
    return 0;
}
