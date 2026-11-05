#include <iostream>
#include <string>
#include <cstring>
#define MAX 1000000
int n, m, parent[MAX], visited[MAX];
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
    if(parent[a] < parent[b])
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
    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        std::string t;
        std::cin >> t;
        for(int j = 0; j < m; j++)
        {
            int nx = i, ny = j;
            if(t[j] == 'U')
            {
                --nx;
            }
            else if(t[j] == 'D')
            {
                ++nx;
            }
            else if(t[j] == 'L')
            {
                --ny;
            }
            else
            {
                ++ny;
            }
            Union(i * m + j, nx * m + ny);
        }
    }
    int ans = 0;
    for(int i = 0; i < n * m; i++)
    {
        int p = Find(i);
        if(!visited[p])
        {
            visited[p] = true;
            ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}