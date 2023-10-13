#include <iostream>
#include <vector>
#include <stack>
#define MAX 2000
int n, m, visited[MAX];
std::vector<int> link[MAX];
bool dfs(int now, int count)
{
    if(count == 5)
    {
        return true;
    }
    for(auto next : link[now])
    {
        if(visited[next])
        {
            continue;
        }
        visited[next] = 1;
        if(dfs(next, count + 1))
        {
            return true;
        }
        visited[next] = 0;
    }
    return false;
}
bool solve()
{
    for(int i = 0; i < n; i++)
    {
        visited[i] = 1;
        if(dfs(i, 1))
        {
            return true;
        }
        visited[i] = 0;
    }
    return false;
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
        link[a].push_back(b);
        link[b].push_back(a);
    }
    std::cout << solve() << '\n';
    return 0;
}