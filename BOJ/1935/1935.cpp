#include <iostream>
#include <string>
#include <stack>
double values[26];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed;
    std::cout.precision(2);
    int n;
    std::string expr;
    std::stack<double> stk;
    std::cin >> n >> expr;
    for(int i = 0; i < n; i++)
    {
        std::cin >> values[i];
    }
    for(char token : expr)
    {
        if(token >= 'A' && token <= 'Z')
        {
            stk.push(values[token - 'A']);
            continue;
        }
        double right = stk.top();
        stk.pop();
        double left = stk.top();
        stk.pop();
        if(token == '+')
        {
            stk.push(left + right);
        }
        else if(token == '-')
        {
            stk.push(left - right);
        }
        else if(token == '*')
        {
            stk.push(left * right);
        }
        else
        {
            stk.push(left / right);
        }
    }
    std::cout << stk.top() << '\n';
    return 0;
}
