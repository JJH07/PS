// Copyright © 2020 진준호. All rights reserved.

#include <algorithm>
#include <iostream>
#include <string>

int n, m, dp[50][50];
bool onPath[50][50], checked[50][50];
constexpr int dr[4] = {1, 0, -1, 0};
constexpr int dc[4] = {0, 1, 0, -1};
std::string board[50];

bool isValid(int row, int col)
{
    return row >= 0 && row < n && col >= 0 && col < m && board[row][col] != 'H';
}

bool hasCycle(int row, int col)
{
    if(!isValid(row, col) || checked[row][col])
    {
        return false;
    }
    if(onPath[row][col])
    {
        return true;
    }
    onPath[row][col] = true;
    const int jump = board[row][col] - '0';
    for(int i = 0; i < 4; i++)
    {
        if(hasCycle(row + dr[i] * jump, col + dc[i] * jump))
        {
            return true;
        }
    }
    onPath[row][col] = false;
    checked[row][col] = true;
    return false;
}

int maxMoves(int row, int col)
{
    if(!isValid(row, col))
    {
        return 0;
    }
    int &result = dp[row][col];
    if(result != -1)
    {
        return result;
    }
    result = 0;
    const int jump = board[row][col] - '0';
    for(int i = 0; i < 4; i++)
    {
        result = std::max(result, 1 + maxMoves(row + dr[i] * jump, col + dc[i] * jump));
    }
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int row = 0; row < n; row++)
    {
        std::cin >> board[row];
        std::fill(dp[row], dp[row] + m, -1);
    }
    std::cout << (hasCycle(0, 0) ? -1 : maxMoves(0, 0)) << '\n';
    return 0;
}
