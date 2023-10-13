#include <iostream>
#include <stack>
#include <string>

bool isBalanced(std::string str)
{
    std::stack<char> stk;
    for(char c : str)
    {
        if(c == '(' || c == '[')
        {
            stk.push(c);
        }
        else if(c == ')' || c == ']')
        {
            if(stk.empty())
            {
                return false;
            }
            char top = stk.top();
            stk.pop();
            if(c == ')' && top != '(' || c == ']' && top != '[')
            {
                return false;
            }
        }
    }
    return stk.empty();
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string str;
    while(1)
    {
        std::getline(std::cin, str);
        if(str[0] == '.')
        {
            break;
        }
        std::cout << (isBalanced(str) ? "yes\n" : "no\n"); 
    }
    return 0; 
}