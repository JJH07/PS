#include <functional>
#include <iostream>
#include <queue>
#include <vector>
int n, m, indegree[32001];
std::vector<int> adj[32001];
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int from, to;
        std::cin >> from >> to;
        adj[from].push_back(to);
        indegree[to]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(indegree[i] == 0)
        {
            pq.push(i);
        }
    }
    while(!pq.empty())
    {
        int node = pq.top();
        pq.pop();
        std::cout << node << ' ';
        for(int x : adj[node])
        {
            indegree[x]--;
            if(indegree[x] == 0)
            {
                pq.push(x);
            }
        }
    }
    return 0;
}
