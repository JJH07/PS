#include <iostream>
#include <vector>
#include <cstring>

int building[1001], dp[1001];
std::vector<int> prerequisite[1001];
int construct(int idx)
{
    int &ret = dp[idx];
    if(ret != -1)
    {
        return ret;
    }
    ret = building[idx];
    for(auto x : prerequisite[idx])
    {
        ret = std::max(ret, building[idx] + construct(x));
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while(T--)
    {
        int n, k, W;
        std::cin >> n >> k;

        for(int i = 1; i <= n; i++)
        {
            prerequisite[i].clear();
        }
        std::memset(dp, -1, sizeof(dp));

        for(int i = 1; i <= n; i++)
        {
            std::cin >> building[i];
        }
        for(int i = 0; i < k; i++)
        {
            int X, Y;
            std::cin >> X >> Y;
            prerequisite[Y].push_back(X);
        }
        std::cin >> W;
        std::cout << construct(W) << '\n';
    }
    return 0;
}