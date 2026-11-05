#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000
std::vector<int> ans;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    while(!(std::cin >> n).eof())
    {
        for(int i = 0; i < n; i++)
        {
            int chart;
            std::cin >> chart;
            if(ans.empty() || ans.back() < chart)
            {
                ans.push_back(chart);
            }
            else
            {
                auto idx = std::lower_bound(ans.begin(), ans.end(), chart);
                *idx = chart;
            }
        }
        std::cout << ans.size() << '\n';
        ans.clear();
    }
    return 0;
}