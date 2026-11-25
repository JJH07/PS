#include <iostream>
#include <cstring>
#include <vector>
const int MAX = 101;

int n, m, match[MAX];
std::vector<int> adj[MAX];
bool visited[MAX];
bool dfs(int person)
{
    for(int notebook : adj[person])
    {
        if(visited[notebook])
        {
            continue;
        }
        visited[notebook] = true;
        if(match[notebook] == 0 || dfs(match[notebook]))
        {
            match[notebook] = person;
            return true;
        }
    }
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        adj[a].push_back(b);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        std::memset(visited, 0, sizeof(visited));
        if(dfs(i))
        {
            ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}
