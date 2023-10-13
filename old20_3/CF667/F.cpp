#include <iostream>
#include <string>
#include <cstring>

int n, k;
std::string s, t;
bool SAME;
int dp[201][201][201];
int solve(int idx, int k, int first)
{
    if(idx == n)
    {
        return 0;
    }
    int &ret = dp[idx][k][first];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    if(s[idx] == t[0])
    {
        ret = std::max(ret, SAME ? first : 0 + solve(idx + 1, k, first + 1));
    }
    if(s[idx] == t[1])
    {
        ret = std::max(ret, first + solve(idx + 1, k, first + SAME));
    }
    if(k > 0)
    {
        if(s[idx] != t[0])
        {
            ret = std::max(ret, SAME ? first : 0 + solve(idx + 1, k - 1, first + 1));
        }
        if(s[idx] != t[1])
        {
            ret = std::max(ret, first + solve(idx + 1, k - 1, first + SAME));
        }
    }
    if(s[idx] != t[0] && s[idx] != t[1])
    {
        ret = std::max(ret, solve(idx + 1, k, first));
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));

    std::cin >> n >> k >> s >> t;
    SAME = t[0] == t[1];
    std::cout << solve(0, k, 0) << '\n';
    return 0;
}