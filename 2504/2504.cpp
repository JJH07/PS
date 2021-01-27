#include <iostream>
#include <stack>
#include <string>
typedef std::pair<char, int> pci;
std::string str;
int solve()
{
    std::stack<pci> stk;
    int num = 0;
    for(char c : str)
    {
        if(c == '(' || c == '[')
        {
            stk.push({c, num});
            num = 0;
            continue;
        }
        if(stk.empty())
        {
            return 0;
        }
        pci top = stk.top();
        stk.pop();
        if((top.first == '(' && c != ')') || (top.first == '[' && c != ']'))
        {
            return 0;
        }
        if(c == ')')
        {
            num = (num == 0 ? 2 : num * 2) + top.second;
        }
        else
        {
            num = (num == 0 ? 3 : num * 3) + top.second;
        }
    }
    return stk.empty() ? num : 0;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> str;
    std::cout << solve() << '\n';
    return 0;
}