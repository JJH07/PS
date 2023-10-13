#include <iostream>
#include <cstring>
#define MAX 2001
typedef long long ll;
int n;
ll list[MAX], dp[MAX][MAX];
ll solve(int now, int S, int H)
{
    if(now > n)
    {
        return 0;
    }
    ll &ret = dp[S][H];
    if(ret != -1)
    {
        return ret;
    }
    ll nS = (S == 0 ? 0 : std::abs(list[S] - list[now])) + solve(now + 1, now, H);
    ll nH = (H == 0 ? 0 : std::abs(list[H] - list[now])) + solve(now + 1, S, now);
    return ret = std::min(nS, nH);
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> list[i];
    }
    ll ans = solve(1, 0, 0);
    std::cout << ans << '\n';
    return 0;
}