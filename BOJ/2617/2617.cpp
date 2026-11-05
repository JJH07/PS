#include <iostream>
#include <vector>
#include <cstring>
#define MAX 100
int n, m;
bool visited[MAX];
std::vector<int> link[MAX][2];
int dfs(int now, int offset)
{
    visited[now] = true;
    int ret = 0;
    for(int next : link[now][offset])
    {
        if(!visited[next])
        {
            ret += 1 + dfs(next, offset);
        }
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        link[a][0].push_back(b);
        link[b][1].push_back(a);
    }

    int ans = 0, mid = (n + 1) / 2;
    for(int i = 1; i <= n; i++)
    {
        std::memset(visited, 0, sizeof(visited));
        int a = dfs(i, 0);
        std::memset(visited, 0, sizeof(visited));
        int b = dfs(i, 1);
        if(a >= mid || b >= mid)
        {
            ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}