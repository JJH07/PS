#include <iostream>
#include <cstring>

int parent[100001];
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
    if(x > y)
    {
        parent[x] = y;
    }
    else
    {
        parent[y] = x;
    }
    
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(parent, -1, sizeof(parent));

    int G, P, cnt = 0;

    std::cin >> G >> P;
    for(int i = 0; i < P; i++)
    {
        int idx;
        std::cin >> idx;
        int p = Find(idx);
        if(p == 0)
        {
            break;
        }
        Union(p - 1, idx);
        cnt++;
    }
    std::cout << cnt << '\n';
    return 0;
}