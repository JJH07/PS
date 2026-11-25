#include <iostream>
#include <queue>
#include <cstring>

constexpr int MAX = 100001;
struct Edge
{
    int from, to, weight;
    bool operator<(const Edge &rhs)const{
        return weight > rhs.weight;
    }
};
int parent[MAX];
int findRoot(int idx)
{
    if(parent[idx] == -1)
    {
        return idx;
    }
    return parent[idx] = findRoot(parent[idx]);
}
bool unite(int a, int b)
{
    a = findRoot(a);
    b = findRoot(b);
    if(a == b)
    {
        return false;
    }
    parent[b] = a;
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::memset(parent, -1, sizeof(parent));

    std::priority_queue<Edge> pq;
    int n, m;
    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, weight;
        std::cin >> a >> b >> weight;
        pq.push({a, b, weight});
    }
    int totalCost = 0, selected = 0;
    while(!pq.empty() && selected < n - 2)
    {
        auto [from, to, weight] = pq.top();
        pq.pop();
        if(unite(from, to))
        {
            totalCost += weight;
            selected++;
        }
    }
    std::cout << totalCost << '\n';
    return 0;
}
