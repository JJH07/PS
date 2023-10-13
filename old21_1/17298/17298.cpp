#include <iostream>
#include <stack>
#define MAX 1000000
typedef std::pair<int, int> pii;
int n, ans[MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::stack<pii> stk;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int number;
        std::cin >> number;
        if(stk.empty() || stk.top().first > number)
        {
            stk.push({number, i});
        }
        else
        {
            while(!stk.empty())
            {
                auto [before, index] = stk.top();
                if(before >= number)
                {
                    break;
                }
                ans[index] = number;
                stk.pop();
            }
            stk.push({number, i});
        }
    }
    for(int i = 0; i < n; i++)
    {
        std::cout << (ans[i] > 0 ? ans[i] : -1) << ' ';
    }
    return 0;
}