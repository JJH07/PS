// Copyright © 2020 진준호. All rights reserved.

#include <iostream>

using ull = unsigned long long;
constexpr ull MOD = 987654321;
ull dp[10001];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    dp[0] = 1;
    dp[2] = 1;
    for(int size = 4; size <= n; size += 2)
    {
        for(int left = 0, right = size - 2; left <= right; left += 2, right -= 2)
        {
            const ull ways = dp[left] * dp[right] % MOD;
            dp[size] = (dp[size] + (left == right ? ways : 2 * ways)) % MOD;
        }
    }
    std::cout << dp[n] << '\n';
    return 0;
}
