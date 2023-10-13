#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define MAX_V 100000000000
typedef long long ll;

int n, m;
ll pos[1001], w[1001], dp[1001][1001][2];

ll solve(int s, int e, int way)
{
    if(s == 1 && e == n)
    {
        return 0;
    }
    ll &ret = dp[s][e][way];
    if(ret != -1)
    {
        return ret;
    }
    ret = MAX_V;
    int now_idx = (way == 0) ? s : e;
    if(s > 1)
    {
        ret = std::min(ret, solve(s - 1, e, 0) + (pos[now_idx] - pos[s - 1]) * (w[s - 1] + w[n] - w[e]));
    }
    if(e < n)
    {
        ret = std::min(ret, solve(s, e + 1, 1) + (pos[e + 1] - pos[now_idx]) * (w[s - 1] + w[n] - w[e]));
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::fill(dp[0][0], dp[0][0] + 1001 * 1001 * 2, -1);

    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int w_t;
        std::cin >> pos[i] >> w_t;
        w[i] = w[i - 1] + w_t;
    }
    std::cout << solve(m, m, 0) << '\n';
    return 0;
}