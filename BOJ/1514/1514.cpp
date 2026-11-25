// Copyright © 2020 진준호. All rights reserved.

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

int n, dp[100][11][11][11], digits[100], target[100];
int solve(int pos, int a, int b, int c)
{
    if(pos >= n)
    {
        return 0;
    }
    int &result = dp[pos][a][b][c];
    if(result != -1)
    {
        return result;
    }
    int turns = 1;
    int d = (pos + 3 < n) ? digits[pos + 3] : 10;
    if(a == target[pos])
    {
        return result = solve(pos + 1, b, c, d);
    }
    if(std::min((10 + a - target[pos]) % 10, (10 + target[pos] - a) % 10) > 3)
    {
        turns = 2;
    }

    result = turns + solve(pos + 1, b, c, d);
    for(int i = 1; i <= 3; i++)
    {
        result = std::min(result, 1 + solve(pos, (a + i) % 10, (b + i) % 10, c));
        result = std::min(result, 1 + solve(pos, (a + i) % 10, (b + i) % 10, (c + i) % 10));
        result = std::min(result, 1 + solve(pos, (10 + a - i) % 10, (10 + b - i) % 10, c));
        result = std::min(result, 1 + solve(pos, (10 + a - i) % 10, (10 + b - i) % 10, (10 + c - i) % 10));
    }
    return result;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::memset(dp, -1, sizeof(dp));

    std::string text;
    std::cin >> n;
    std::cin >> text;
    for(int i = 0; i < n; i++)
    {
        digits[i] = (int)(text[i] - '0');
    }
    std::cin >> text;
    for(int i = 0; i < n; i++)
    {
        target[i] = (int)(text[i] - '0');
    }
    std::cout << solve(0, digits[0], digits[1], digits[2]) << '\n';
    return 0;
}
