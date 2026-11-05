#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, list[1001], dp[1001], sz = -1;
    std::vector<int> ans;
    std::cin >> n;
    
    std::fill(dp, dp + 1001, 1);

    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i; j < n; j++)
        {
            if(list[i] < list[j])
            {
                dp[j] = std::max(dp[j], dp[i] + 1);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        sz = std::max(sz, dp[i]);
    }

    int t_sz = sz;
    int t_max = 1e9;
    for(int i = n - 1; i >= 0; i--)
    {
        if(dp[i] == t_sz && list[i] < t_max)
        {
            ans.push_back(list[i]);
            t_sz--;
            t_max = list[i];
        }   
    }
    std::cout << sz << '\n';
    for(int i = sz - 1; i >= 0; i--)
    {
        std::cout << ans[i] << ' ';
    }
    return 0;
}