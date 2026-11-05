#include <iostream>
#include <cstring>
#include <cmath>
#define MAX 3000
struct group{
    int x, y, r;
};
group g[MAX];
int n, parent[MAX];

bool check(int x, int y)
{
    group &a = g[x];
    group &b = g[y];
    double dist = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    if(double(a.r + b.r) >= dist)
    {
        return true;
    }
    return false;
}
int Find(int idx)
{
    if(parent[idx] == -1)
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
    parent[x] = y;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        std::memset(parent, -1, sizeof(parent));
        std::cin >>  n;
        for(int i = 0; i < n; i++)
        {
            std::cin >> g[i].x >> g[i].y >> g[i].r;
        }
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(check(i, j))
                {
                    Union(i, j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(parent[i] == -1)
            {
                ans++;
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}