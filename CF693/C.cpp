#include <iostream>
#include <cstring>
const int MAX = 2e5;
int n, proc[MAX + 1], dp[MAX + 1];
int go(int idx)
{
    if(idx > n)
    {
        return 0;
    }
    int &ret = dp[idx];
    if(ret != -1)
    {
        return ret;
    }
    return ret = proc[idx] + go(idx + proc[idx]);
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--)
    {
        std::memset(dp, -1, sizeof(dp));
        std::cin >> n;
        for(int i = 1; i <= n; i++)
        {
            std::cin >> proc[i];
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            ans = std::max(ans, go(i));
        }
        std::cout << ans << '\n';
    }
    return 0;
}