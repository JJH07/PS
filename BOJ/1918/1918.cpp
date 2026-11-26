#include <iostream>
#include <stack>
#include <string>

int precedence(char op)
{
    if(op == '+' || op == '-')
    {
        return 1;
    }
    if(op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string expr, postfix;
    std::stack<char> ops;
    std::cin >> expr;
    postfix.reserve(expr.size());
    for(char token : expr)
    {
        if('A' <= token && token <= 'Z')
        {
            postfix += token;
        }
        else if(token == '(')
        {
            ops.push(token);
        }
        else if(token == ')')
        {
            while(ops.top() != '(')
            {
                postfix += ops.top();
                ops.pop();
            }
            ops.pop();
        }
        else
        {
            while(!ops.empty() && ops.top() != '(' &&
                  precedence(ops.top()) >= precedence(token))
            {
                postfix += ops.top();
                ops.pop();
            }
            ops.push(token);
        }
    }
    while(!ops.empty())
    {
        postfix += ops.top();
        ops.pop();
    }
    std::cout << postfix << '\n';
    return 0;
}
