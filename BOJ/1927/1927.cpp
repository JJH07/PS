#include <iostream>
#include <vector>
#include <functional>
#include <queue>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    std::cin >> n;
    while(n--)
    {
        int value;
        std::cin >> value;
        if(value > 0)
        {
            pq.push(value);
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
