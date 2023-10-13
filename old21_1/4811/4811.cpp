#include <iostream>
#include <cstring>
typedef long long ll;
ll dp[31][61];
ll solve(int full, int half)
{
    ll &ret = dp[full][half];
    if(ret != -1)
    {
        return ret;
    }
    ret = (full + half == 0) ? 1 : 0;
    if(full > 0)
    {
        ret += solve(full - 1, half + 1);
    }
    if(half > 0)
    {
        ret += solve(full, half - 1);
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));
    while(1)
    {
        int n;
        std::cin >> n;
        if(n == 0)
        {
            break;
        }
        std::cout << solve(n, 0) << '\n';
    }
    return 0;
}