#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#define MAX 200001

int parent[MAX];
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
    if(parent[x] < parent[y])
    {
        parent[x] += parent[y];
        parent[y] = x;
    }
    else
    {
        parent[y] += parent[x];
        parent[x] = y;
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::map<std::string, int> list;
    std::cin >> t;
    while(t--)
    {    
        std::memset(parent, -1, sizeof(parent));
        list.clear();
        int f, cnt = 0;
        std::cin >> f;
        while(f--)
        {
            std::string a, b;
            std::cin >> a >> b;
            if(list.find(a) == list.end())
            {
                list.insert({a, cnt++});
            }
            if(list.find(b) == list.end())
            {
                list.insert({b, cnt++});
            }
            Union(list[a], list[b]);
            std::cout << -parent[Find(list[a])] << '\n';
        }
    }
    return 0;
}