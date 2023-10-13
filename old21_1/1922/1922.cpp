#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
typedef std::pair<int, int> PII;
int n, m;
std::vector<PII> link[MAX];
bool visited[MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        if(a == b)
        {
            continue;
        }
        link[a].push_back({b, c});
        link[b].push_back({a, c});
    }
    int ans = 0;
    std::priority_queue<PII> pq;
    for(auto [y, c] : link[1])
    {
        pq.push({-c, y});
    }
    visited[1] = 1;
    while(!pq.empty())
    {
        auto [c, now] = pq.top();
        pq.pop();
        if(visited[now])
        {
            continue;
        }
        ans += -c;
        visited[now] = 1;
        for(auto next : link[now])
        {
            if(!visited[next.first])
            {
                pq.push({-next.second, next.first});
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}