#include <iostream>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x;
    std::priority_queue<int> pq;
    std::cin >> x;
    while(x)
    {
        pq.push(x % 10);
        x /= 10;
    }
    while(!pq.empty())
    {
        const int digit = pq.top();
        pq.pop();
        std::cout << digit;
    }
    return 0;
}
