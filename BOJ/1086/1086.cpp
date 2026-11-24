// Copyright © 2020 진준호. All rights reserved.

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>

int n, mod;
long long dp[100][1 << 15];
int pow10[51], lengths[15], remainders[15];
std::string numbers[15];

long long countWays(int remainder, int mask)
{
    if(mask == (1 << n) - 1)
    {
        return remainder == 0 ? 1 : 0;
    }
    long long &result = dp[remainder][mask];
    if(result != -1)
    {
        return result;
    }
    result = 0;
    for(int i = 0; i < n; i++)
    {
        if(mask & (1 << i))
        {
            continue;
        }
        const int next = (remainder * pow10[lengths[i]] + remainders[i]) % mod;
        result += countWays(next, mask | (1 << i));
    }
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> numbers[i];
        lengths[i] = numbers[i].size();
    }
    std::cin >> mod;

    for(auto &row : dp)
    {
        std::fill(row, row + (1 << 15), -1);
    }
    pow10[0] = 1 % mod;
    for(int i = 1; i <= 50; i++)
    {
        pow10[i] = pow10[i - 1] * 10 % mod;
    }
    for(int i = 0; i < n; i++)
    {
        for(char digit : numbers[i])
        {
            remainders[i] = (remainders[i] * 10 + digit - '0') % mod;
        }
    }

    long long numerator = countWays(0, 0);
    long long denominator = 1;
    for(int i = 2; i <= n; i++)
    {
        denominator *= i;
    }
    const long long divisor = std::gcd(numerator, denominator);
    std::cout << numerator / divisor << '/' << denominator / divisor << '\n';
    return 0;
}
