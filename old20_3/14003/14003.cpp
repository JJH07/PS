#include <iostream>
#include <vector>
#include <algorithm>

int n, list[1000000], dp[1000000];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::vector<int> buf;

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i];
    }

    buf.push_back(list[0]);
    dp[0] = 1;
    for(int i = 1; i < n; i++)
    {
        if(buf.back() < list[i])
        {
            buf.push_back(list[i]);
            dp[i] = buf.size();
        }
        else
        {
            auto it = std::lower_bound(buf.begin(), buf.end(), list[i]);
            *it = list[i];
            dp[i] = it - buf.begin() + 1;
        }
    }
    int sz = (int)buf.size(), keep = 1000000001;
    std::cout << sz << '\n';
    std::vector<int> ans;
    for(int i = n - 1; i >= 0; i--)
    {
        if(sz == 0)
        {
            break;
        }
        if(sz == dp[i] && list[i] < keep)
        {
            ans.push_back(list[i]);
            sz--;
            keep = list[i];
        }
    }
    for(auto x = ans.rbegin(); x != ans.rend(); x++)
    {
        std::cout << *x << ' ';
    }
    return 0;
}