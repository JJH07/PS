#include <iostream>
#include <vector>
#include <cstring>
#define MAX 10001

int Time[MAX], dp[MAX];
std::vector<int> Prerequisite[MAX];
int solve(int idx)
{
    int &ret = dp[idx];
    if(ret != -1)
    {
        return ret;
    }
    ret = Time[idx];
    for(auto &next : Prerequisite[idx])
    {
        ret = std::max(ret, Time[idx] + solve(next));
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));
    int n;
    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int c;
        std::cin >> Time[i] >> c;
        while(c--)
        {
            int p;
            std::cin >> p;
            Prerequisite[i].push_back(p);
        }
    }
    int ans = -1;
    for(int i = 1; i <= n; i++)
    {
        ans = std::max(ans, solve(i));
    }
    std::cout << ans << '\n';
    return 0;
}