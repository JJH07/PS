#include <iostream>
#include <stack>
#define MAX 1000000
typedef std::pair<int, int> pii;
int list[MAX], F[MAX + 1], ans[MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::stack<int> stk;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i];
        F[list[i]]++;
    }
    for(int i = 0; i < n; i++)
    {
        while(!stk.empty())
        {
            int top = stk.top();
            if(F[list[top]] >= F[list[i]])
            {
                break;
            }
            ans[top] = list[i];
            stk.pop();

        }
        stk.push(i);
    }
    while(!stk.empty())
    {
        ans[stk.top()] = -1;
        stk.pop();
    }
    for(int i = 0; i < n; i++)
    {
        std::cout << ans[i] << ' ';
    }
    return 0;
}