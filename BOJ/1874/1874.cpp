#include <iostream>
#include <stack>
#include <vector>
int n;
std::stack<int> stk;
std::vector<char> ops;
bool simulate()
{
    int next = 1;
    for(int i = 0; i < n; i++)
    {
        int target;
        std::cin >> target;
        while(next <= target)
        {
            stk.push(next++);
            ops.push_back('+');
        }
        if(stk.top() != target)
        {
            return false;
        }
        stk.pop();
        ops.push_back('-');
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    ops.reserve(2 * n);
    if(simulate())
    {
        for(auto x : ops)
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
