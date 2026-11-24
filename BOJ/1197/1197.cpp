#include <iostream>
#include <queue>

struct Edge
{
    int from, to;
    long long weight;

    bool operator<(const Edge &other) const
    {
        return weight > other.weight;
    }
};

int parent[10001];

int findRoot(int node)
{
    if(parent[node] == 0)
    {
        return node;
    }
    return parent[node] = findRoot(parent[node]);
}

bool unite(int a, int b)
{
    a = findRoot(a);
    b = findRoot(b);
    if(a == b)
    {
        return false;
    }
    parent[a] = b;
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int vertices, edges;
    std::cin >> vertices >> edges;
    std::priority_queue<Edge> queue;
    for(int i = 0; i < edges; i++)
    {
        Edge edge;
        std::cin >> edge.from >> edge.to >> edge.weight;
        queue.push(edge);
    }

    long long totalWeight = 0;
    int selected = 0;
    while(!queue.empty() && selected < vertices - 1)
    {
        const Edge edge = queue.top();
        queue.pop();
        if(unite(edge.from, edge.to))
        {
            totalWeight += edge.weight;
            selected++;
        }
    }
    std::cout << totalWeight << '\n';
    return 0;
}
