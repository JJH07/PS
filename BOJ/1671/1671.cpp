#include <algorithm>
#include <iostream>
#include <vector>

constexpr int MAX = 51;

struct Shark
{
    int size, speed, intel;
};

Shark sharks[MAX];
std::vector<int> adj[MAX];
int n, match[MAX];
bool visited[MAX];

void buildEdges()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
            {
                continue;
            }
            const Shark &a = sharks[i];
            const Shark &b = sharks[j];
            const bool equal = a.size == b.size && a.speed == b.speed && a.intel == b.intel;
            if(equal && i > j)
            {
                continue;
            }
            if(a.size >= b.size && a.speed >= b.speed && a.intel >= b.intel)
            {
                adj[i].push_back(j);
            }
        }
    }
}

bool dfs(int shark)
{
    for(int next : adj[shark])
    {
        if(visited[next])
        {
            continue;
        }
        visited[next] = true;
        if(match[next] == 0 || dfs(match[next]))
        {
            match[next] = shark;
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
    for(int i = 1; i <= n; i++)
    {
        std::cin >> sharks[i].size >> sharks[i].speed >> sharks[i].intel;
    }
    buildEdges();
    int eaten = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int attempt = 0; attempt < 2; attempt++)
        {
            std::fill(visited, visited + MAX, false);
            if(dfs(i))
            {
                eaten++;
            }
        }
    }
    std::cout << n - eaten << '\n';
    return 0;
}
