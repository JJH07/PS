#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

typedef long long ll;
std::vector<std::pair<int, ll>> link[100001];
int parent[100001][17], level[100001];
ll dist[100001][17];

void bfs()
{
    bool visited[100001];
    std::queue<std::pair<int, int>> q;

    std::memset(visited, 0, sizeof(visited));

    visited[1] = 1;
    level[1] = 1;
    q.push({1, 1});

    while(!q.empty())
    {
        auto [now, lv] = q.front();
        q.pop();

        for(auto [next, w] : link[now])
        {
            if(!visited[next])
            {
                visited[next] = 1;
                level[next] = lv + 1;
                q.push({next, lv + 1});
                parent[next][0] = now;
                dist[next][0] = w;
            }
        }
    }
}
ll get_price(int s, int e)
{
    ll ans = 0;
    if(level[s] > level[e])
    {
        std::swap(s, e);
    }
    int diff = level[e] - level[s];
    for(int i = 0; diff > 0; i++)
    {
        if(diff % 2)
        {
            ans += dist[e][i];
            e = parent[e][i];
        }
        diff /= 2;
    }
    if(s != e)
    {
        for(int i = 16; i >= 0; i--)
        {
            if(parent[s][i] > 0 && parent[s][i] != parent[e][i])
            {
                ans += dist[s][i] + dist[e][i];
                s = parent[s][i];
                e = parent[e][i];
            }
        }
        ans += dist[s][0] + dist[e][0];
    }
    return ans;
}
int get_vertex(int s, int e, int k)
{
    int top_level = 0;
    int x = s, y = e;
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
        for(int i = 16; i >= 0; i--)
        {
            if(parent[x][i] > 0 && parent[x][i] != parent[y][i])
            {
                x = parent[x][i];
                y = parent[y][i];
            }
        }
        x = parent[x][0];
    }
    top_level = level[x];
    
    if(level[s] - top_level >= k)
    {
        diff = k;
        y = s;
    }
    else
    {
        diff = (level[e] - top_level) - (k - level[s] + top_level);
        y = e;
    }
    for(int i = 0; diff > 0; i++)
    {
        if(diff % 2)
        {
            y = parent[y][i];
        }
        diff /= 2;
    }
    return y;
}

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        ll w;
        std::cin >> u >> v >> w;
        link[u].push_back({v, w});
        link[v].push_back({u, w});
    }
    bfs();
    for(int j = 0; j < 16; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(parent[i][j] > 0)
            {
                parent[i][j + 1] = parent[parent[i][j]][j];
                dist[i][j + 1] = dist[i][j] + dist[parent[i][j]][j];
            }
        }
    }
    std::cin >> m;
    while(m--)
    {
        int op, u, v;
        std::cin >> op >> u >> v;
        if(op == 1)
        {
            std::cout << get_price(u, v) << '\n';
        }
        else
        {
            int k;
            std::cin >> k;
            std::cout << get_vertex(u, v, k - 1) << '\n';
        }
    }
    return 0;
}