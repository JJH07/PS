#include <iostream>
#include <stack>
typedef std::pair<int, int> pii;
int n;
std::stack<pii> stk;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int h, ans = 0;
        std::cin >> h;
        while(!stk.empty())
        {
            auto [n, idx] = stk.top();
            if(n > h)
            {
                ans = idx;
                break;
            }
            stk.pop();
        }
        stk.push({h, i});
        std::cout << ans << '\n';
    }
    return 0;
}