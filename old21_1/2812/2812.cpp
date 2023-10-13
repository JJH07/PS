#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k;
    std::string str;
    std::stack<char> stk;
    std::cin >> n >> k >> str;
    for(char c : str)
    {
        while(!stk.empty())
        {
            if(k == 0 || stk.top() >= c)
            {
                break;
            }
            stk.pop();
            k--;
        }
        stk.push(c);
    }
    std::string ans;
    while(!stk.empty())
    {
        if(k > 0)
        {
            k--;
        }
        else
        {
            ans += stk.top();
        }
        stk.pop();
    }
    std::reverse(ans.begin(), ans.end());
    std::cout << ans << '\n';
    return 0;
}