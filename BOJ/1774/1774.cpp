#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
struct pqn{
    int x, y;
    double dist;
    bool operator<(const pqn &rhs)const{
        return dist > rhs.dist;
    }
};
int parent[1001];

double inline fx(std::pair<double, double> &x, std::pair<double, double> &y)
{
    return sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
}
int Find(int idx)
{
    if(parent[idx] < 0)
    {
        return idx;
    }
    return parent[idx] = Find(parent[idx]);
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y)
    {
        return ;
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
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::fixed;
    std::cout.precision(2);
    std::memset(parent, -1, sizeof(parent));

    int n, m;
    std::pair<double, double> pos[1001];
    std::priority_queue<pqn> pq;
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> pos[i].first >> pos[i].second;
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            pq.push({i, j, fx(pos[i], pos[j])});
        }
    }
    for(int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        Union(a, b);
    }
    double ans = 0;
    while(!pq.empty())
    {
        auto [x, y, d] = pq.top();
        pq.pop();
        if(Find(x) == Find(y))
        {
            continue;
        }
        Union(x, y);
        ans += d;
    }
    std::cout << ans << '\n';
    return 0;
}