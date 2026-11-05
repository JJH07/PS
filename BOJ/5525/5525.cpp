#include <iostream>
#include <string>
#include <stack>
int n, m;
std::string str;
std::stack<char> stk;
int check()
{
    int ret = 0;
    if(stk.empty())
    {
        return 0;
    }
    if(stk.top() == 'O')
    {
        stk.pop();
    }
    while(!stk.empty())
    {
        if(stk.top() == 'O')
        {
            ++ret;
        }
        stk.pop();
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    int ans = 0;
    std::cin >> n >> m >> str;
    str += str.back();
    for(auto c : str)
    {
        if(c == 'I')
        {
            if(!stk.empty() && stk.top() == c)
            {
                int P = check();
                ans += (P >= n) ? P - n + 1 : 0;
            }
            stk.push(c);
        }
        else
        {
            if(stk.empty() || stk.top() == c)
            {
                int P = check();
                ans += (P >= n) ? P - n + 1 : 0;
            }
            if(!stk.empty())
            {
                stk.push(c);
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}