#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
typedef std::pair<int, int> pii;
bool comp(const pii &a, const pii &b)
{
    return a.second < b.second;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, ans = 0;
    std::vector<pii> list;
    std::stack<pii> stk;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int L, H;
        std::cin >> L >> H;
        list.push_back({L, H});
    }
    std::sort(list.begin(), list.end());
    auto max_it = std::max_element(list.begin(), list.end(), comp);

    for(int i = 0; i < (max_it - list.begin()); i++)
    {
        if(stk.empty() || stk.top().second < list[i].second)
        {
            stk.push(list[i]);
        }
    }
    int e = max_it->first;
    while(!stk.empty())
    {
        auto [L, H] = stk.top();
        stk.pop();
        ans += H * (e - L);
        e = L;
    }
    for(int i = n - 1; i > (max_it - list.begin()); i--)
    {
        if(stk.empty() || stk.top().second < list[i].second)
        {
            stk.push(list[i]);
        }
    }
    e = max_it->first;
    while(!stk.empty())
    {
        auto [L, H] = stk.top();
        stk.pop();
        ans += H * (L - e);
        e = L;
    }
    std::cout << ans + max_it->second << '\n';
    return 0;
}