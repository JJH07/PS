#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    std::cin >> n;
    while(n--)
    {
        int card;
        std::cin >> card;
        pq.push(card);
    }
    int ans = 0;
    while(pq.size() > 1)
    {
        int top = pq.top();
        pq.pop();
        top += pq.top();
        pq.pop();
        pq.push(top);
        ans += top;
    }
    std::cout << ans << '\n';
    return 0;
}