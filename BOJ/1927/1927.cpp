#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    std::cin >> n;
    while(n--)
    {
        int number;
        std::cin >> number;
        if(number > 0)
        {
            pq.push(number);
            continue;
        }
        if(pq.empty())
        {
            std::cout << 0 << '\n';
        }
        else
        {
            std::cout << pq.top() << '\n';
            pq.pop();
        }
    }
    return 0;
}