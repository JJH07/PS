#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 100001
struct road{
    int x, y, c;
    bool operator<(const road &rhs)const{
        return c > rhs.c;
    }
};
int parent[MAX];
int Find(int idx)
{
    if(parent[idx] == -1)
    {
        return idx;
    }
    return parent[idx] = Find(parent[idx]);
}
bool Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a == b)
    {
        return false;
    }
    parent[b] = a;
    return true;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::memset(parent, -1, sizeof(parent));
    
    std::priority_queue<road> pq;
    int n, m;
    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        pq.push({a, b, c});
    }
    int ans = 0, cnt = 0;
    while(!pq.empty())
    {
        if(cnt == n - 2)
        {
            break;
        }
        auto [x, y, c] = pq.top();
        pq.pop();
        if(Union(x, y))
        {
            ans += c;
            cnt++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}