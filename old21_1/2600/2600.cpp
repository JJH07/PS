#include <bits/stdc++.h>
#define MAX 501
int b[3], dp[MAX][MAX];
int solve(int k1, int k2)
{
    int &ret = dp[k1][k2];
    if(ret != -1)
    {
        return ret;
    }
    ret = 0;
    for(int i = 0; i < 3; i++)
    {
        if(k1 >= b[i] && !solve(k1 - b[i], k2))
        {
            return ret = 1;
        }
        if(k2 >= b[i] && !solve(k1, k2 - b[i]))
        {
            return ret = 1;
        }
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    std::cin >> b[0] >> b[1] >> b[2];
    for(int i = 0; i < 5; i++)
    {
        int k1, k2;
        std::cin >> k1 >> k2;
        std::cout << (solve(k1, k2) ? "A\n" : "B\n");
    }
    return 0;
}