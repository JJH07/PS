#include <iostream>
#include <vector>
#include <cstring>
constexpr int MAX = 20;
int n, match[MAX];
bool visited[MAX];
std::vector<int> adj[MAX];
bool dfs(int diag)
{
    if(visited[diag])
    {
        return false;
    }
    visited[diag] = true;
    for(auto next : adj[diag])
    {
        if(match[next] == 0 || dfs(match[next]))
        {
            match[next] = diag;
            return true;
        }
    }
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int pos;
            std::cin >> pos;
            if(pos == 1)
            {
                adj[i + j + 1].push_back(5 - i + j);
            }
        }
    }
    int count = 0;
    for(int i = 1; i < 2 * n; i++)
    {
        std::memset(visited, 0, sizeof(visited));
        if(dfs(i))
        {
            count++;
        }
    }
    std::cout << count << '\n';
    return 0;
}
