#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

constexpr int MAX = 10001;
using Edge = std::pair<int, int>;
int indegree[MAX], dist[MAX];
std::vector<Edge> adj[MAX], reverseAdj[MAX];

void longestPaths(int start)
{
    std::queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto [next, weight] : adj[node])
        {
            dist[next] = std::max(dist[next], dist[node] + weight);
            if(--indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }
}

int countCritical(int target)
{
    bool visited[MAX]{};
    std::queue<int> q;
    q.push(target);
    visited[target] = true;
    int edgeCount = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto [prev, weight] : reverseAdj[node])
        {
            if(dist[prev] + weight != dist[node])
            {
                continue;
            }
            edgeCount++;
            if(!visited[prev])
            {
                visited[prev] = true;
                q.push(prev);
            }
        }
    }
    return edgeCount;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int from, to, weight;
        std::cin >> from >> to >> weight;
        adj[from].push_back({to, weight});
        reverseAdj[to].push_back({from, weight});
        indegree[to]++;
    }
    int start, target;
    std::cin >> start >> target;
    longestPaths(start);
    std::cout << dist[target] << '\n' << countCritical(target) << '\n';
    return 0;
}
