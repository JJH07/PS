#include <iostream>
#include <algorithm>
#include <vector>
constexpr int MAX = 501;

int n, k, match[MAX];
bool visited[MAX];
std::vector<int> adj[MAX];
bool dfs(int row)
{
    if(visited[row])
    {
        return false;
    }
    visited[row] = true;
    for(int col : adj[row])
    {
        if(match[col] == 0 || dfs(match[col]))
        {
            match[col] = row;
            return true;
        }
    }
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> k;
    for(int i = 0; i < k; i++)
    {
        int a, b;
        std::cin >> a >> b;
        adj[a].push_back(b);
    }
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        std::fill(visited, visited + n + 1, false);
        if(dfs(i))
        {
            count++;
        }
    }
    std::cout << count << '\n';
    return 0;
}
