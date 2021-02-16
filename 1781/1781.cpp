#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 200000
typedef std::pair<int, int> pii;
int n;
pii Problem[MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::priority_queue<int> pq;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> Problem[i].first >> Problem[i].second;
    }
    std::sort(Problem, Problem + n);
    for(int i = 0; i < n; i++)
    {
        auto [Deadline, Noodle] = Problem[i];
        if(pq.size() < Deadline)
        {
            pq.push(-Noodle);
            continue;
        }
        int top = pq.top();
        if(-top < Noodle)
        {
            pq.pop();
            pq.push(-Noodle);
        }
    }
    int ans = 0;
    while(!pq.empty())
    {
        ans += -pq.top();
        pq.pop();
    }
    std::cout << ans << '\n';
    return 0;
}