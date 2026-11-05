#include <bits/stdc++.h>
#define MAX 1 << 20
int n, map[20][20], dp[MAX];
void flip(int x)
{
    for(int y = 0; y < n; y++)
    {
        map[x][y] = map[x][y] ? 0 : 1;
    }
}
int count()
{
    int ret = 0;
    for(int y = 0; y < n; y++)
    {
        int c = 0;
        for(int x = 0; x < n; x++)
        {
            c += map[x][y];
        }
        ret += std::min(c, n - c);
    }
    return ret;
}
int solve(int state)
{
    int &ret = dp[state];
    if(ret != -1)
    {
        return ret;
    }
    ret = count();
    for(int next = 0; next < n; next++)
    {
        if(state & (1 << next))
        {
            continue;
        }
        flip(next);
        ret = std::min(ret, solve(state + (1 << next)));
        flip(next);
    }
    return ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char c;
            std::cin >> c;
            if(c == 'T')
            {
                map[i][j] = 1;
            }
        }
    }
    std::cout << solve(0) << '\n';
    return 0;
}