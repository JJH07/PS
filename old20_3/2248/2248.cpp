#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long ll;
int N, L;
ll I, dp[32][32];
ll solve(int n, int l)
{
    if(n == 0 || l == 0)
    {
        return 1;
    }
    ll &ret = dp[n][l];
    if(ret != -1)
    {
        return ret;
    }
    ret = solve(n - 1, l) + (l > 0 ? solve(n - 1, l - 1) : 0);
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::fill(dp[0], dp[0] + 32 * 32, -1);

    std::cin >> N >> L >> I;
    while(1)
    {
        if(N == 0 || L == 0)
        {
            for(int i = 0; i < N; i++)
            {
                std::cout << '0';
            }
            break;
        }
        ll t = solve(N - 1, L);
        if(I > t)
        {
            std::cout << '1';
            I -= t;
            L--;
        }
        else
        {
            std::cout << '0';
        }
        N--;
    }
    return 0;
}