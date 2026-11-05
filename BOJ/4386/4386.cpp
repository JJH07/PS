#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>

struct qn{
    int s, e;
    double dist;
    bool operator<(const qn &rhs) const{
        return dist > rhs.dist;
    }
};
int parent[101];
std::pair<double, double> star[101];
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
    std::memset(parent, -1, sizeof(parent));
    std::cout << std::fixed;
    std::cout.precision(2);

    int n;
    double ans = 0;
    std::priority_queue<qn> pq;

    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> star[i].first >> star[i].second;
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            pq.push({i, j, fx(star[i], star[j])});
        }
    }
    while(!pq.empty())
    {
        auto min = pq.top();
        pq.pop();
        if(Find(min.s) == Find(min.e))
        {
            continue;
        }
        Union(min.s, min.e);
        ans += min.dist;
    }
    std::cout << ans << '\n';
    return 0;
}