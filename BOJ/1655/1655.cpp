#include <iostream>
#include <queue>
#include <algorithm>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, mid = 10001;
    std::priority_queue<int> l;
    std::priority_queue<int, std::vector<int>, std::greater<int>> r;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int number;
        std::cin >> number;
        if(mid > number)
        {
            l.push(number);
        }
        else
        {
            r.push(number);
        }
        while(l.size() < r.size())
        {
            l.push(r.top());
            r.pop();
        }
        while(l.size() > r.size() + 1)
        {
            r.push(l.top());
            l.pop();
        }
        mid = l.top();
        std::cout << mid << '\n';
    }
    return 0;
}

