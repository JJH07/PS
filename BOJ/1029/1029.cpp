#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int n, prices[15][15], dp[15][10][1 << 15];
int solve(int now, int price, int state)
{
    int &ret = dp[now][price][state];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    for(int i = 1; i < n; i++)
    {
        int next = (1 << i);
        if(state & next)
        {
            continue;
        }
        if(prices[now][i] >= price)
        {
            ret = std::max(ret, 1 + solve(i, prices[now][i], state + next));
        }
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::fill(dp[0][0], dp[0][0] + 15 * 10 * (1 << 15), -1);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::string t;
        std::cin >> t;
        for(int j = 0; j < n; j++)
        {
            prices[i][j] = t[j] - '0';
        }
    }
    std::cout << 1 + solve(0, 0, 1) << '\n';
    return 0;
}