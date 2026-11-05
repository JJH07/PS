#include <iostream>
#include <stack>
#include <vector>
int n;
std::stack<int> stk;
std::vector<char> ans;
bool simulate()
{
    int idx = 1;
    for(int i = 0; i < n; i++)
    {
        int number;
        std::cin >> number;
        while(idx <= number)
        {
            stk.push(idx++);
            ans.push_back('+');
        }
        if(stk.top() != number)
        {
            return false;
        }
        stk.pop();
        ans.push_back('-');
    }
    return true;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    if(simulate())
    {
        for(auto x : ans)
        {
            std::cout << x << '\n';
        }
    }
    else
    {
        std::cout << "NO\n";
    }

    return 0;
}