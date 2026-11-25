// Copyright © 2020 진준호. All rights reserved.

#include <cstring>
#include <iostream>
#include <set>

constexpr int MOD = 9901;
int n, m, dp[14][1 << 14];

int solve(int row, int mask)
{
    if(row == n)
    {
        return mask == 0 ? 1 : 0;
    }
    int &result = dp[row][mask];
    if(result != -1)
    {
        return result;
    }
    result = 0;
    const int fullMask = (1 << m) - 1;
    std::set<int> states{mask};
    for(auto it = states.begin(); it != states.end(); ++it)
    {
        const int filled = *it;
        for(int col = 0; col < m - 1; col++)
        {
            const int pairMask = 3 << col;
            if((filled & pairMask) == 0)
            {
                states.insert(filled | pairMask);
            }
        }
        const int nextMask = fullMask ^ filled;
        result = (result + solve(row + 1, nextMask)) % MOD;
    }
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    std::memset(dp, -1, sizeof(dp));
    std::cout << solve(0, 0) << '\n';
    return 0;
}
