#include <iostream>
#include <stack>
#define MAX 80000
typedef long long ll;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::stack<int> stk;
    ll n, ans = 0;
    std::cin >> n;
    while(n--)
    {
        int h;
        std::cin >> h;
        while(!stk.empty())
        {
            if(stk.top() > h)
            {
                break;
            }
            stk.pop();
        }
        ans += stk.size();
        stk.push(h);
    }
    std::cout << ans << '\n';
    return 0;
}