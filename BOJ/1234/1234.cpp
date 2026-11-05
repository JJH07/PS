#include <iostream>
#include <algorithm>
typedef long long ll;
ll N, R, G, B, memo[11][101][101][101], permutation[11];
ll solve(int level, int r, int g, int b)
{
    if(level > N)
    {
        return 1;
    }
    ll &ret = memo[level][r][g][b];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    if(level <= r)
    {
        ret += solve(level + 1, r - level, g, b);
    }
    if(level <= g)
    {
        ret += solve(level + 1, r, g - level, b);
    }
    if(level <= b)
    {
        ret += solve(level + 1, r, g, b - level);
    }
    if(level % 2 == 0)
    {
        int div = level / 2;
        ll mul = permutation[level] / permutation[div] / permutation[div];
        if(div <= r && div <= g)
        {
            ret += solve(level + 1, r - div, g - div, b) * mul;
        }
        if(div <= g && div <= b)
        {
            ret += solve(level + 1, r, g - div, b - div) * mul;
        }
        if(div <= r && div <= b)
        {
            ret += solve(level + 1, r - div, g, b - div) * mul;
        }
    }
    if(level % 3 == 0)
    {
        int div = level / 3;
        ll mul = permutation[level] / permutation[div] / permutation[div] / permutation[div];
        if(div <= r && div <= g && div <= b)
        {
            ret += solve(level + 1, r - div, g - div, b - div) * mul;
        }
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::fill(memo[0][0][0], memo[0][0][0] + 11 * 101 * 101 * 101, -1);
    permutation[0] = 1;
    for(int i = 1; i <= 10; i++)
    {
        permutation[i] = permutation[i - 1] * i;
    }

    std::cin >> N >> R >> G >> B;
    ll ans = solve(1, R, G, B);

    std::cout << ans << '\n';
    return 0;
}