#include <iostream>
#include <stack>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int k, ans = 0;
    std::stack<int> stk;
    std::cin >> k;
    while(k--)
    {
        int number;
        std::cin >> number;
        if(number == 0)
        {
            stk.pop();
        }
        else
        {
            stk.push(number);
        }
    }
    while(!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }
    std::cout << ans << '\n';
    return 0;
}