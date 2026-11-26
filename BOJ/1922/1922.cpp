#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
constexpr int MAX = 1001;
typedef std::pair<int, int> Entry;
int n, m;
std::vector<Entry> adj[MAX];
bool visited[MAX];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        if(a == b)
        {
            continue;
        }
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    int total = 0;
    std::priority_queue<Entry, std::vector<Entry>, std::greater<Entry>> pq;
    for(auto [y, c] : adj[1])
    {
        pq.push({c, y});
    }
    visited[1] = true;
    int selected = 1;
    while(!pq.empty() && selected < n)
    {
        auto [c, node] = pq.top();
        pq.pop();
        if(visited[node])
        {
            continue;
        }
        total += c;
        visited[node] = true;
        selected++;
        for(auto next : adj[node])
        {
            if(!visited[next.first])
            {
                pq.push({next.second, next.first});
            }
        }
    }
    std::cout << total << '\n';
    return 0;
}
