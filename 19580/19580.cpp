#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#define MAX 500001
typedef long long ll;
struct node{
    ll l, r;
    node(ll L, ll R) : l(L), r(R) {}
    bool operator<(const node &rhs) const{
        if(r == rhs.r)
        {
            return l < rhs.l;
        }
        return r > rhs.r;
    }
};
int n, m;
std::priority_queue<node> pq;
std::map<ll, int> store;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        ll l, r;
        std::cin >> l >> r;
        pq.push(node(l, r));
    }
    for(int i = 0; i < m; i++)
    {
        ll p;
        int c;
        std::cin >> p >> c;
        if(store.find(p) == store.end())
        {
            store.insert({p, c});
        }
        else
        {
            store[p] += c;
        }
    }
    int ans = 0;
    while(!pq.empty() && !store.empty())
    {
        auto [LEFT, RIGHT] = pq.top();
        pq.pop();
        auto it = store.lower_bound(LEFT);
        if(it == store.end())
        {
            continue;
        }
        if(it->first > RIGHT)
        {
            continue;
        }
        it->second--;
        ans++;
        if(it->second == 0)
        {
            store.erase(it);
        }
    }
    std::cout << ans << '\n';
    return 0;
}