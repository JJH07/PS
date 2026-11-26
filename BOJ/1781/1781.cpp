#include <functional>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
constexpr int MAX = 200000;
typedef std::pair<int, int> pii;
int n;
pii jobs[MAX];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int total = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> jobs[i].first >> jobs[i].second;
    }
    std::sort(jobs, jobs + n);
    for(int i = 0; i < n; i++)
    {
        auto [deadline, reward] = jobs[i];
        if(pq.size() < static_cast<std::size_t>(deadline))
        {
            pq.push(reward);
            total += reward;
            continue;
        }
        int lowest = pq.top();
        if(lowest < reward)
        {
            pq.pop();
            pq.push(reward);
            total += reward - lowest;
        }
    }
    std::cout << total << '\n';
    return 0;
}
