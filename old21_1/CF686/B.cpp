#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int n;
        std::vector<std::pair<int, int>> list;
        std::cin >> n;
        for(int i = 1; i <= n; i++)
        {
            int a;
            std::cin >> a;
            list.push_back({a, i});
        }
        std::sort(list.begin(), list.end());
        int ans = -1;
        for(int i = 0; i < list.size(); i++)
        {
            int s = i;
            int e = i + 1;
            while(e < list.size())
            {
                if(list[e].first != list[s].first)
                {
                    break;
                }
                e++;
            }
            if(e - s == 1)
            {
                ans = list[s].second;
                break;
            }
            i = e - 1;
        }
        std::cout << ans << '\n';
    }
    return 0;
}