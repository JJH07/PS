#include <iostream>
#include <stack>
#define MAX 500000
typedef std::pair<int, int> pii;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    long long n, ans = 0;
    std::stack<pii> stk;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int h;
        std::cin >> h;
        while(!stk.empty())
        {
            auto [number, cnt] = stk.top();
            if(number >= h)
            {
                break;
            }
            stk.pop();
            ans += cnt;
        }
        if(stk.empty())
        {
            stk.push({h, 1});
        }
        else if(stk.top().first == h)
        {
            auto [number, cnt] = stk.top();
            stk.pop();
            ans += cnt + !stk.empty();
            stk.push({h, cnt + 1});
        }
        else
        {
            stk.push({h, 1});
            ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}