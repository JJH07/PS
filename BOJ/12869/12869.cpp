#include <bits/stdc++.h>
#define INF 1e9
std::vector<int> SCV(3);
int dp[61][61][61];
int solve(std::vector<int> state)
{
    if(state[0] + state[1] + state[2] == 0)
    {
        return 0;
    }
    int &ret = dp[state[0]][state[1]][state[2]];
    if(ret != -1)
    {
        return ret;
    }
    ret = INF;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(i == j || i == k || j == k)
                {
                    continue;
                }
                std::vector<int> temp = state;
                temp[i] = temp[i] >= 9 ? temp[i] - 9 : 0;
                temp[j] = temp[j] >= 3 ? temp[j] - 3 : 0;
                temp[k] = temp[k] >= 1 ? temp[k] - 1 : 0; 
                ret = std::min(ret, 1 + solve(temp));
            }
        }
    }
    return ret == INF ? 0 : ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> SCV[i];
    }
    std::cout << solve(SCV) << '\n';
    return 0;
}