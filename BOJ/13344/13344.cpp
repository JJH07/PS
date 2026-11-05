#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

int n, m, cnt;
int parent[50001], visited[50001];
std::vector<std::pair<int, int>> list;
std::vector<int> next[50001];
int Find(int idx)
{
    if(parent[idx] < 0)
    {
        return idx;
    }
    return parent[idx] = Find(parent[idx]);
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x == y)
    {
        return ;
    }
    if(parent[x] > parent[y])
    {
        std::swap(x, y);
    }
    parent[x] += parent[y];
    parent[y] = x;
}
bool check(int idx)
{
    if(visited[idx])
    {
        return (visited[idx] == -1 ? 1 : 0);
    }
    visited[idx] = -1;
    for(auto &x : next[idx])
    {
        if(check(x))
        {
            return 1;
        }
    }
    visited[idx] = 1;
    return 0;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(parent, -1, sizeof(parent));

    bool VALID = true;
    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        char opt;
        std::cin >> a >> opt >> b;
        if(opt == '=')
        {
            Union(a, b);
        }
        else
        {
            list.push_back({a, b});
        }
    }
    for(auto &x : list)
    {
        int u = Find(x.first);
        int v = Find(x.second);
        next[u].push_back(v);
    }
    for(int i = 0; i < n; i++)
    {
        if(check(i))
        {
            std::cout << "in";
            break;
        }
    }
    std::cout << "consistent\n";
    return 0;
}