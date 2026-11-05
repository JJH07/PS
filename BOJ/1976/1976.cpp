#include <iostream>
#include <cstring>

int parent[1000001];
int Find(int idx)
{
    if(parent[idx] < 0)
    {
        return idx;
    }
    return parent[idx] = Find(parent[idx]);
}
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a == b)
    {
        return ;
    }
    if(parent[a] > parent[b])
    {
        parent[b] += parent[a];
        parent[a] = b;
    }
    else
    {
        parent[a] += parent[b];
        parent[b] = a;
    } 
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(parent, -1, sizeof(parent));

    int n, m, route[1001];
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            bool tmp;
            std::cin >> tmp;
            if(tmp)
            {
                Union(i, j);
            }
        }
    }
    for(int i = 0; i < m; i++)
    {
        std::cin >> route[i];
    }

    bool FLAG = false;
    int group = Find(route[0]);
    for(int i = 1; i < m; i++)
    {
        if(group != Find(route[i]))
        {
            FLAG = true;
            break;
        }
    }
    std::cout << (FLAG ? "NO\n" : "YES\n");
    return 0;
}