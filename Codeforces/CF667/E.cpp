#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define INF 1e9
#define MAX 200000
typedef std::pair<int, int> pii;

int n, k, memo[MAX + 1][2];
std::vector<int> pos;
int solve(int idx, int number)
{
    if(number == 2)
    {
        return 0;
    }
    int &ret = memo[idx][number];
    if(ret != -1)
    {
        return ret;
    }
    int x = pos[idx];
    auto lit = std::lower_bound(pos.begin(), pos.end(), x);
    auto uit = std::upper_bound(pos.begin(), pos.end(), x + k);
    if(uit == pos.end())
    {
        return ret = uit - lit;
    }
    ret = uit - lit + solve(uit - pos.begin(), number + 1);
    return ret = std::max(ret, solve(std::upper_bound(pos.begin(), pos.end(), x) - pos.begin(), number));
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        pos.clear();
        std::cin >> n >> k;
        for(int i = 1; i <= n; i++)
        {
            int x;
            std::cin >> x;
            pos.push_back(x);
        }
        for(int i = 1; i <= n; i++)
        {
            int y;
            std::cin >> y;
        }
        std::sort(pos.begin(), pos.end());
        std::memset(memo, -1, sizeof(memo));
        std::cout << solve(0, 0) << '\n';
    }
    return 0;
}