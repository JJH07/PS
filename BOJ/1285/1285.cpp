#include <algorithm>
#include <iostream>

constexpr int MAX_N = 20;
int n, board[MAX_N][MAX_N], dp[1 << MAX_N];

void flipRow(int row)
{
    for(int col = 0; col < n; col++)
    {
        board[row][col] ^= 1;
    }
}

int minTails()
{
    int total = 0;
    for(int col = 0; col < n; col++)
    {
        int tails = 0;
        for(int row = 0; row < n; row++)
        {
            tails += board[row][col];
        }
        total += std::min(tails, n - tails);
    }
    return total;
}

int solve(int mask)
{
    int &result = dp[mask];
    if(result != -1)
    {
        return result;
    }
    result = minTails();
    for(int row = 0; row < n && result > 0; row++)
    {
        if(mask & (1 << row))
        {
            continue;
        }
        flipRow(row);
        result = std::min(result, solve(mask | (1 << row)));
        flipRow(row);
    }
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    std::fill(dp, dp + (1 << n), -1);
    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < n; col++)
        {
            char coin;
            std::cin >> coin;
            board[row][col] = coin == 'T';
        }
    }
    std::cout << solve(0) << '\n';
    return 0;
}
