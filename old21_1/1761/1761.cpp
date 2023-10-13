#include <iostream>
#include <vector>
#define MAX 40001
#define DEPTH 16
typedef long long ll;
typedef std::pair<int, ll> pii;
int n, m, level[MAX], parent[MAX][DEPTH];
ll distance[MAX];
std::vector<pii> link[MAX];
void dfs(int now, int lv)
{
    for(auto [next, dist] : link[now])
    {
        if(level[next] == 0)
        {
            level[next] = lv + 1;
            distance[next] = distance[now] + dist;
            parent[next][0] = now;
            dfs(next, lv + 1);
        }
    }
}
ll solve(int x, int y)
{
    ll ret = distance[x] + distance[y];
    if(level[x] > level[y])
    {
        std::swap(x, y);
    }
    int diff = level[y] - level[x];
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
        for(int i = DEPTH - 1; i >= 0; i--)
        {
            if(parent[x][i] > 0 && parent[x][i] != parent[y][i])
            {
                x = parent[x][i];
                y = parent[y][i];
            }
        }
        x = parent[x][0];
    }
    ret -= distance[x] * 2;
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        ll c;
        std::cin >> a >> b >> c;
        link[a].push_back({b, c});
        link[b].push_back({a, c});
    }
    level[1] = 1;
    dfs(1, 1);
    for(int j = 0; j < DEPTH; j++)
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
        ll ans = solve(a, b);
        std::cout << ans << '\n';
    }
    return 0;
}