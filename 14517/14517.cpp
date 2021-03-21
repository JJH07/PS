#include <iostream>
#include <string>
#include <cstring>
#define MOD 10007
#define MAX 1000
std::string S;
int dp[MAX][MAX];
int solve(int s, int e)
{
    if(s == e)
    {
        return 1;
    }
    if(s > e)
    {
        return 0;
    }
    int &ret = dp[s][e];
    if(ret != -1)
    {
        return ret;
    }
    ret = ((solve(s, e - 1) + solve(s + 1, e)) % MOD) - solve(s + 1, e - 1);
    if(S[s] == S[e])
    {
        ret = ((((ret % MOD) + MOD) % MOD) + 1 + solve(s + 1, e - 1)) % MOD;
    }
    return ret = ((ret % MOD) + MOD) % MOD;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));
    std::cin >> S;
    std::cout << solve(0, S.length() - 1) << '\n';
    return 0;
}