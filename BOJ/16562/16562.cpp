#include <iostream>
#include <queue>
#include <cstring>
#define MAX 10001
typedef std::pair<int, int> pii;
int n, m, k, parent[MAX], w[MAX];
int Find(int idx)
{
    if(parent[idx] == -1)
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
    parent[a] = b;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(parent, -1, sizeof(parent));
    std::priority_queue<pii> pq;
    std::cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> w[i];
        pq.push({-w[i], i});
    }
    for(int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        Union(a, b);
    }
    int ans = 0;
    while(!pq.empty())
    {
        auto [W, idx] = pq.top();
        pq.pop();
        int junseok = Find(0);
        int f = Find(idx);
        if(junseok == f)
        {
            continue;
        }
        Union(junseok, f);
        ans += -W;
    }
    if(ans > k)
    {
        std::cout << "Oh no\n";
    }
    else
    {
        std::cout << ans << '\n';
    }
    return 0;
}