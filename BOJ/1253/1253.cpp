#include <bits/stdc++.h>
const int MAX = INT_MAX;
int n;
std::vector<int> v;
std::set<int> good;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int ans = 0, num;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> num;
        v.push_back(num);
    }
    std::sort(v.begin(), v.end());
    for(auto i = v.begin(); i < v.end(); i++)
    {
        int flag = 0;
        for(auto j = v.begin(); !flag && j < v.end(); j++)
        {
            if(i == j)
            {
                continue;
            }
            int num = *i - *j;
            auto lit = std::lower_bound(v.begin(), v.end(), num);
            auto uit = std::upper_bound(v.begin(), v.end(), num);
            if(lit == v.end() || *lit != num)
            {
                continue;
            }
            for(auto it = lit; it < uit; it++)
            {
                if(it != i && it != j)
                {
                    flag = 1;
                    break;
                }
            }
        }
        ans += flag;
    }
    std::cout << ans << '\n';
    return 0;
}