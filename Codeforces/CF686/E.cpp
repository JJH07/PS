#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#define MAX 200001
typedef long long ll;
int n, d[MAX], FLAG[MAX];
std::vector<int> link[MAX], route, cycle;
int init(int now, int parent)
{
    d[now] = route.size();
    route.push_back(now);
    for(int next : link[now])
    {
        if(next == parent)
        {
            continue;
        }
        if(d[next] != -1)
        {
            for(int i = d[next]; i < route.size(); i++)
            {
                FLAG[route[i]] = 1;
                cycle.push_back(route[i]);
            }
            return 1;
        }
        else if(init(next, now))
        {
            return 1;
        }
    }
    route.pop_back();
    return 0;
}
int dfs(int now, int parent)
{
    int ret = 1;
    for(int next : link[now])
    {
        if(next != parent && !FLAG[next])
        {
            ret += dfs(next, now);
        }
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        std::cin >> n;
        for(int i = 0; i < n; i++)
        {
            int a, b;
            std::cin >> a >> b;
            link[a].push_back(b);
            link[b].push_back(a);
        }
        std::memset(d, -1, sizeof(d));
        std::memset(FLAG, 0, sizeof(FLAG));
        init(1, 0);
        ll ans = 0;
        for(int x : cycle)
        {
            int t = dfs(x, 0);
            ans += 1LL * t * (t - 1) / 2;
            ans += 1LL * t * (n - t); 
        }
        std::cout << ans << '\n';
        for(int i = 0; i <= n; i++)
        {
            link[i].clear();
        }
        route.clear();
        cycle.clear();
    }
    return 0;
}