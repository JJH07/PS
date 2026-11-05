#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

typedef long long ll;

struct route{
    int A, B;
    ll dist;
    bool operator<(const route &rhs) const{
        return dist > rhs.dist;
    }
};
int V, E;
int parent[10001];
int Find(int idx)
{
    if(parent[idx] == 0)
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

    ll v = 0;
    std::priority_queue<route> pq;

    std::cin >> V >> E;
    for(int i = 0; i < E; i++)
    {
        int A, B;
        ll C;
        std::cin >> A >> B >> C;
        pq.push({A, B, C});
    }
    while(!pq.empty())
    {
        route min = pq.top();
        if(Find(min.A) != Find(min.B))
        {
            Union(min.A, min.B);
            v += min.dist;
        }
        pq.pop();
    }
    std::cout << v << '\n';
    return 0;
}