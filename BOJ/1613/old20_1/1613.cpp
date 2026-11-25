// Copyright © 2019 진준호. All rights reserved.

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

constexpr int MAX = 401;
int visited[MAX];
std::vector<int> adj[MAX];

bool canReach(int from, int to)
{
    std::queue<int> q;
    q.push(from);
    visited[from] = 1;
    while(!q.empty())
    {
        const int node = q.front();
        q.pop();
        if(node == to)
        {
            return true;
        }
        for(int next : adj[node])
        {
            if(!visited[next])
            {
                visited[next] = 1;
                q.push(next);
            }
        }
    }
    return false;
}

int compareEvents(int a, int b)
{
    std::fill(visited, visited + MAX, 0);
    if(canReach(a, b))
    {
        return -1;
    }
    visited[a] = 0;
    return canReach(b, a) ? 1 : 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k, queries;
    std::cin >> n >> k;
    for(int i = 0; i < k; i++)
    {
        int from, to;
        std::cin >> from >> to;
        adj[from].push_back(to);
    }
    std::cin >> queries;
    for(int i = 0; i < queries; i++)
    {
        int a, b;
        std::cin >> a >> b;
        std::cout << compareEvents(a, b) << '\n';
    }
    return 0;
}
