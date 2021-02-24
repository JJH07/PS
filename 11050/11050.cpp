#include <iostream>
#include <cstring>
int dp[11][11];
int C(int n, int r)
{
    int &ret = dp[n][r];
    if(ret != -1)
    {
        return ret;
    }
    if(r == 0 || n == r)
    {
        return ret = 1;
    }
    return ret = C(n - 1, r - 1) + C(n - 1, r);
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));
    int n, k;
    std::cin >> n >> k;
    std::cout << C(n, k) << '\n';
    return 0;
}