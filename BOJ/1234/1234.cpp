#include <algorithm>
#include <iostream>

int n;
long long dp[11][101][101][101];
long long factorial[11], ways2[11], ways3[11];

long long countWays(int level, int r, int g, int b)
{
    if(level > n)
    {
        return 1;
    }
    long long &result = dp[level][r][g][b];
    if(result != -1)
    {
        return result;
    }
    result = 0;
    if(r >= level)
    {
        result += countWays(level + 1, r - level, g, b);
    }
    if(g >= level)
    {
        result += countWays(level + 1, r, g - level, b);
    }
    if(b >= level)
    {
        result += countWays(level + 1, r, g, b - level);
    }
    if(level % 2 == 0)
    {
        const int half = level / 2;
        if(r >= half && g >= half)
        {
            result += countWays(level + 1, r - half, g - half, b) * ways2[level];
        }
        if(g >= half && b >= half)
        {
            result += countWays(level + 1, r, g - half, b - half) * ways2[level];
        }
        if(r >= half && b >= half)
        {
            result += countWays(level + 1, r - half, g, b - half) * ways2[level];
        }
    }
    if(level % 3 == 0)
    {
        const int third = level / 3;
        if(r >= third && g >= third && b >= third)
        {
            result += countWays(level + 1, r - third, g - third, b - third) * ways3[level];
        }
    }
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for(auto &level : dp)
    {
        for(auto &red : level)
        {
            for(auto &green : red)
            {
                std::fill(green, green + 101, -1);
            }
        }
    }
    factorial[0] = 1;
    for(int i = 1; i <= 10; i++)
    {
        factorial[i] = factorial[i - 1] * i;
        if(i % 2 == 0)
        {
            ways2[i] = factorial[i] / factorial[i / 2] / factorial[i / 2];
        }
        if(i % 3 == 0)
        {
            ways3[i] = factorial[i] / factorial[i / 3] / factorial[i / 3] / factorial[i / 3];
        }
    }
    int r, g, b;
    std::cin >> n >> r >> g >> b;
    std::cout << countWays(1, r, g, b) << '\n';
    return 0;
}
