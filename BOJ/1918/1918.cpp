#include <iostream>
#include <vector>
#include <stack>

int main()
{
    std::cin.sync_with_stdio(false);
	std::cin.tie(NULL);

	std::string str, ans;
	std::stack<char> stk;

	std::cin >> str;
	for (char c : str)
    {
		if ('A' <= c && c <= 'Z')
        {
			ans += c;
		}
		else
        {
			switch (c)
			{
                case '(':
                    stk.push(c);
                    break;
                case '*':
                case '/':
                    while (!stk.empty())
                    {
                        if(stk.top() != '*' && stk.top() != '/')
                        {
                            break;
                        }
                        ans += stk.top();
                        stk.pop();
                    }
                    stk.push(c);
                    break;
                case '+':
                case '-':
                    while (!stk.empty())
                    {
                        if(stk.top() == '(')
                        {
                            break;
                        }
                        ans += stk.top();
                        stk.pop();
                    }
                    stk.push(c);
                    break;
                case ')':
                    while (!stk.empty())
                    {
                        if(stk.top() == '(')
                        {
                            break;
                        }
                        ans += stk.top();
                        stk.pop();
                    }
                    stk.pop();
                    break;
			}
		}
	}
	while (!stk.empty())
    {
		ans += stk.top();
		stk.pop();
	}
	std::cout << ans << "\n";
	return 0;
}