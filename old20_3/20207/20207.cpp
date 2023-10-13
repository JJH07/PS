#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
bool comp(const std::pair<int, int> &A, const std::pair<int, int> &B)
{
    if(A.first == B.first)
    {
        return A.second > B.second;
    }
    return A.first < B.first;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, S[367];
    std::vector<std::pair<int, int>> list;
    std::memset(S, 0, sizeof(S));
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        list.push_back({a, b});
    }
    std::sort(list.begin(), list.end(), comp);

    for(auto x : list)
    {
        for(int i = x.first; i <= x.second; i++)
        {
            S[i]++;
        }
    }
    int len = 0, lv = 0, ans = 0;
    for(int i = 1; i <= 366; i++)
    {
        if(S[i] > 0)
        {
            len++;
            lv = std::max(lv, S[i]);
        }
        else
        {
            ans += (len * lv);
            len = 0;
            lv = 0;
        }
    }
    std::cout << ans << '\n';
    return 0;
}