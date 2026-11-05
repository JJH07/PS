#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

typedef long long ll;
struct pqn{
    int x, y;
    ll dist;
    bool operator<(const pqn &rhs)const{
        return dist > rhs.dist;
    }
};
int parent[100001];
std::vector<std::pair<ll, int>> x, y, z;
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
    std::priority_queue<pqn> pq;
    int n;
    std::cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        ll a, b, c;
        std::cin >> a >> b >> c;
        x.push_back({a, i});
        y.push_back({b, i});
        z.push_back({c, i});
    }
    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end());
    std::sort(z.begin(), z.end());
    for(int i = 0; i < n - 1; i++)
    {
        pq.push({x[i].second, x[i + 1].second, abs(x[i].first - x[i + 1].first)});
        pq.push({y[i].second, y[i + 1].second, abs(y[i].first - y[i + 1].first)});
        pq.push({z[i].second, z[i + 1].second, abs(z[i].first - z[i + 1].first)});
    }

    ll ans = 0;
    while(!pq.empty())
    {
        auto [x, y, dist] = pq.top();
        pq.pop();
        if(Find(x) == Find(y))
        {
            continue;
        }
        Union(x, y);
        ans += dist;
    }
    std::cout << ans << '\n';
    return 0;
}