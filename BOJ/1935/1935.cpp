#include <iostream>
#include <string>
#include <stack>
double table[26];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::fixed;
    std::cout.precision(2);
    int n;
    std::string op;
    std::stack<double> stk;
    std::cin >> n >> op;
    for(int i = 0; i < n; i++)
    {
        std::cin >> table[i];
    }
    for(char c : op)
    {
        if(c >= 'A' && c <= 'Z')
        {
            stk.push(table[c - 'A']);
            continue;
        }
        double y = stk.top();
        stk.pop();
        double x = stk.top();
        stk.pop();
        if(c == '+')
        {
            stk.push(x + y);
        }
        else if(c == '-')
        {
            stk.push(x - y);
        }
        else if(c == '*')
        {
            stk.push(x * y);
        }
        else
        {
            stk.push(x / y);
        }
    }
    std::cout << stk.top() << '\n';
    return 0;
}