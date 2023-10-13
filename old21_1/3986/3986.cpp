#include <iostream>
#include <string>
#include <stack>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, ans = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::string str;
        std::stack<char> stk;
        std::cin >> str;
        for(char c : str)
        {
            if(stk.empty())
            {
                stk.push(c);
            }
            else if(stk.top() == c)
            {
                stk.pop();
            }
            else
            {
                stk.push(c);
            }
        }
        if(stk.empty())
        {
            ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}