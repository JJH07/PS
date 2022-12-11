#include <bits/stdc++.h>
typedef std::pair<int, int> pii;

struct node{
    int k, s;
    bool operator<(const node &rhs)const{
        return k < rhs.k;
    }
};
int n, t, dp[10001][101];
node list[101];

int solve(int Time, int idx)
{
    int &ret = dp[Time][idx];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    for(int i = idx + 1; i <= n; i++)
    {
        int rest = Time - list[i].k;
        if(rest < 0)
        {
            break;
        }
        ret = std::max(ret, list[i].s + solve(rest, i));
    }
    return ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));

    std::cin >> n >> t;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> list[i].k >> list[i].s;
    }
    std::sort(list + 1, list + n + 1);

    std::cout << solve(t, 0) << '\n';
    return 0;
}