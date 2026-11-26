#include <iostream>
#include <vector>
#include <utility>
constexpr int MAX = 40001;
constexpr int LOG = 16;
typedef long long ll;
typedef std::pair<int, ll> pii;
int n, m, depth[MAX], parent[MAX][LOG];
ll dist[MAX];
std::vector<pii> adj[MAX];
void buildTree()
{
    std::vector<int> stack{1};
    depth[1] = 1;
    while(!stack.empty())
    {
        int node = stack.back();
        stack.pop_back();
        for(auto [next, weight] : adj[node])
        {
            if(depth[next] != 0)
            {
                continue;
            }
            depth[next] = depth[node] + 1;
            dist[next] = dist[node] + weight;
            parent[next][0] = node;
            stack.push_back(next);
        }
    }
}
ll pathCost(int x, int y)
{
    ll cost = dist[x] + dist[y];
    if(depth[x] > depth[y])
    {
        std::swap(x, y);
    }
    int diff = depth[y] - depth[x];
    for(int i = 0; diff > 0; i++)
    {
        if(diff % 2)
        {
            y = parent[y][i];
        }
        diff /= 2;
    }
    if(x != y)
    {
        for(int i = LOG - 1; i >= 0; i--)
        {
            if(parent[x][i] > 0 && parent[x][i] != parent[y][i])
            {
                x = parent[x][i];
                y = parent[y][i];
            }
        }
        x = parent[x][0];
    }
    cost -= dist[x] * 2;
    return cost;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        ll c;
        std::cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    buildTree();
    for(int j = 0; j < LOG; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(parent[i][j] > 0)
            {
                parent[i][j + 1] = parent[parent[i][j]][j];
            }
        }
    }
    std::cin >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        ll ans = pathCost(a, b);
        std::cout << ans << '\n';
    }
    return 0;
}
