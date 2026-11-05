#include <iostream>
#include <vector>
#include <cstring>
#define MAX 9
#define MOD 1000000007
int d, dp[MAX][1000001];
std::vector<int> link[9];
void connect(int a, int b)
{
    link[a].push_back(b);
    link[b].push_back(a);
}
int solve(int now, int time)
{
    if(time == 0)
    {
        return now == 1 ? 1 : 0;
    }
    int &ret = dp[now][time];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    for(auto next : link[now])
    {
        ret = (ret + solve(next, time - 1)) % MOD;
    }
    return ret;
}
void init()
{
    connect(1, 2);
    connect(1, 3);
    connect(2, 3);
    connect(2, 4);
    connect(3, 4);
    connect(3, 5);
    connect(4, 5);
    connect(4, 6);
    connect(5, 6);
    connect(5, 8);
    connect(6, 7);
    connect(7, 8);
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));
    init();
    std::cin >> d;
    std::cout << solve(1, d) << '\n';
    return 0;
}