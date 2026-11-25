//  Copyright © 2020 진준호. All rights reserved.

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>

int n, m, dp[1000][1000];
std::vector<int> a, b;

int solve(int ai, int bi)
{
    if(ai >= n || bi >= m)
    {
        return 0;
    }
    int &cost = dp[ai][bi];
    if(cost != -1)
    {
        return cost;
    }
    cost = 21470000;
    const int diff = std::abs(a[ai] - b[bi]);
    const int skips = (m - n) - (bi - ai);
    for(int i = 0; i <= skips; i++)
    {
        cost = std::min(cost, diff + solve(ai + 1, bi + 1 + i));
    }
    return cost;
}
int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    a.reserve(n);
    b.reserve(m);
    for(int i = 0; i < n; i++)
    {
        int tmp;
        std::cin >> tmp;
        a.push_back(tmp);
    }
    for(int i = 0; i < m; i++)
    {
        int tmp;
        std::cin >> tmp;
        b.push_back(tmp);
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    std::memset(dp, -1, sizeof(dp));

    if(n > m)
    {
        std::swap(a, b);
        std::swap(n, m);
    }
    int answer = 21470000;
    for(int i = 0; i <= m - n; i++)
    {
        answer = std::min(answer, solve(0, i));
    }
    std::cout << answer << '\n';
    return 0;
}
