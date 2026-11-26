#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <utility>
struct Edge{
    int from, to;
    double dist;
    bool operator<(const Edge &rhs)const{
        return dist > rhs.dist;
    }
};
int parent[1001];

double distance(const std::pair<double, double> &a, const std::pair<double, double> &b)
{
    return std::sqrt(std::pow(a.first - b.first, 2) + std::pow(a.second - b.second, 2));
}
int findRoot(int idx)
{
    if(parent[idx] < 0)
    {
        return idx;
    }
    return parent[idx] = findRoot(parent[idx]);
}
bool unite(int x, int y)
{
    x = findRoot(x);
    y = findRoot(y);
    if(x == y)
    {
        return false;
    }
    if(parent[x] > parent[y])
    {
        parent[y] += parent[x];
        parent[x] = y;
    }
    else
    {
        parent[x] += parent[y];
        parent[y] = x;
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed;
    std::cout.precision(2);
    std::memset(parent, -1, sizeof(parent));

    int n, m;
    std::pair<double, double> pos[1001];
    std::priority_queue<Edge> pq;
    std::cin >> n >> m;
    int components = n;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> pos[i].first >> pos[i].second;
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            pq.push({i, j, distance(pos[i], pos[j])});
        }
    }
    for(int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        if(unite(a, b))
        {
            components--;
        }
    }
    double total = 0;
    while(components > 1 && !pq.empty())
    {
        auto [from, to, dist] = pq.top();
        pq.pop();
        if(unite(from, to))
        {
            total += dist;
            components--;
        }
    }
    std::cout << total << '\n';
    return 0;
}
