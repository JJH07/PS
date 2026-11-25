#include <iostream>
#include <queue>
#include <vector>
#include <functional>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    std::cin >> n;
    while(n--)
    {
        int card;
        std::cin >> card;
        pq.push(card);
    }
    int total = 0;
    while(pq.size() > 1)
    {
        int merged = pq.top();
        pq.pop();
        merged += pq.top();
        pq.pop();
        pq.push(merged);
        total += merged;
    }
    std::cout << total << '\n';
    return 0;
}
