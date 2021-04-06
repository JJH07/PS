#include <bits/stdc++.h>
#define MAX 500001
typedef std::pair<int, int> pii;
int n;
std::vector<int> link[MAX];
int dfs()
{
    int ret = 0;
    std::queue<pii> q;
    bool visited[MAX];
    std::memset(visited, 0, sizeof(visited));

    q.push({1, 0});
    visited[1] = true;
    while(!q.empty())
    {
        auto [now, dist] = q.front();
        int pushed = 0;
        q.pop();
        for(int next : link[now])
        {
            if(!visited[next])
            {
                pushed++;
                q.push({next, dist + 1});
                visited[next] = true;
            }
        }
        if(!pushed)
        {
            ret += dist;
        }
    }
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
        std::cin >> a >> b;
        link[a].push_back(b);
        link[b].push_back(a);
    }
    std::cout << (dfs() % 2 ? "Yes\n" : "No\n");
    return 0;
}