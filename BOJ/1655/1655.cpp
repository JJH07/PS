#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::priority_queue<int> lower;
    std::priority_queue<int, std::vector<int>, std::greater<int>> upper;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int number;
        std::cin >> number;
        if(lower.empty() || number < lower.top())
        {
            lower.push(number);
        }
        else
        {
            upper.push(number);
        }
        if(lower.size() < upper.size())
        {
            lower.push(upper.top());
            upper.pop();
        }
        else if(lower.size() > upper.size() + 1)
        {
            upper.push(lower.top());
            lower.pop();
        }
        std::cout << lower.top() << '\n';
    }
    return 0;
}
