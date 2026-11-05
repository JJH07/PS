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

    int n, m;
    std::cin >> n >> m;
    while(m--)
    {
        int op, a, b;
        std::cin >> op >> a >> b;
        if(op)
        {
            std::cout << (Find(a) == Find(b) ? "YES\n" : "NO\n");
        }
        else
        {
            Union(a, b);
        }
        
    }

    return 0;
}