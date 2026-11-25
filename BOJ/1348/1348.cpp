#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>

constexpr int MAP_SIZE = 50;
constexpr int MAX = 100;
constexpr int dr[4] = {1, 0, -1, 0};
constexpr int dc[4] = {0, 1, 0, -1};

struct State
{
    int row, col, dist;
};

int rows, cols, carCount, parkCount;
int grid[MAP_SIZE][MAP_SIZE], match[MAX];
std::vector<std::pair<int, int>> cars, adj[MAX];
bool visited[MAX];

void readInput()
{
    std::cin >> rows >> cols;
    for(int row = 0; row < rows; row++)
    {
        std::string line;
        std::cin >> line;
        for(int col = 0; col < cols; col++)
        {
            if(line[col] == 'C')
            {
                cars.push_back({row, col});
            }
            else if(line[col] == 'P')
            {
                grid[row][col] = ++parkCount;
            }
            else if(line[col] == 'X')
            {
                grid[row][col] = -1;
            }
        }
    }
    carCount = cars.size();
}

void buildEdges()
{
    for(int car = 0; car < carCount; car++)
    {
        bool seen[MAP_SIZE][MAP_SIZE]{};
        std::queue<State> q;
        const auto [row, col] = cars[car];
        q.push({row, col, 0});
        seen[row][col] = true;
        while(!q.empty())
        {
            const State current = q.front();
            q.pop();
            if(grid[current.row][current.col] > 0)
            {
                adj[car].push_back({grid[current.row][current.col] - 1, current.dist});
            }
            for(int dir = 0; dir < 4; dir++)
            {
                const int nextRow = current.row + dr[dir];
                const int nextCol = current.col + dc[dir];
                if(nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols
                    || grid[nextRow][nextCol] == -1 || seen[nextRow][nextCol])
                {
                    continue;
                }
                seen[nextRow][nextCol] = true;
                q.push({nextRow, nextCol, current.dist + 1});
            }
        }
    }
}

bool dfs(int car, int limit)
{
    if(visited[car])
    {
        return false;
    }
    visited[car] = true;
    for(const auto &[park, dist] : adj[car])
    {
        if(dist <= limit && (match[park] == -1 || dfs(match[park], limit)))
        {
            match[park] = car;
            return true;
        }
    }
    return false;
}

bool canMatch(int limit)
{
    std::fill(match, match + MAX, -1);
    for(int car = 0; car < carCount; car++)
    {
        std::fill(visited, visited + MAX, false);
        if(!dfs(car, limit))
        {
            return false;
        }
    }
    return true;
}

int minTime()
{
    int left = 0, right = MAP_SIZE * MAP_SIZE, answer = -1;
    while(left <= right)
    {
        const int mid = (left + right) / 2;
        if(canMatch(mid))
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return answer;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    readInput();
    if(carCount == 0)
    {
        std::cout << "0\n";
    }
    else if(carCount > parkCount)
    {
        std::cout << "-1\n";
    }
    else
    {
        buildEdges();
        std::cout << minTime() << '\n';
    }
    return 0;
}
