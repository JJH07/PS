#include <iostream>
#include <cstring>
#define INF 1e9
int S, dp[2005][2005];
int solve(int length, int copy)
{
    if(length == S)
    {
        return 0;
    }
    int &ret = dp[length][copy];
    if(ret != -1)
    {
        return ret;
    }
    ret = INF;
    if(length > S)
    {
        ret = std::min(ret, 1 + solve(length - 1, copy));
    }
    else
    {
        ret = std::min(ret, 1 + solve(length + copy, copy));
        if(length > 0)
        {
            ret = std::min(ret, 1 + solve(length - 1, copy));
        }
        if(length > copy)
        {
            ret = std::min(ret, 1 + solve(length, length));
        }
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));
    
    std::cin >> S;
    int ans = solve(1, 0);
    std::cout << ans << '\n';
    return 0;
}