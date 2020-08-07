#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

struct stick
{
    ll t;
    ll d;
    stick(ll a, ll b)
    {
        t = a;
        d = b;
    }
    bool operator<(const stick &rhs) const
    {
        if(t == rhs.t)
        {
            return d < rhs.d;
        }
        return t < rhs.t;
    }
};
std::vector<stick> stck;
std::vector<ll> t, d;
ll N, L, tdp[100001], ddp[100001];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    ll ans = 0;
    std::cin >> N >> L;
    for(int i = 0; i < N; i++)
    {
        int a, b;
        std::cin >> a >> b;
        stck.push_back(stick(a, b));
        t.push_back(a);
        d.push_back(b);
    }
    std::sort(stck.begin(), stck.end());
    std::sort(t.begin(), t.end());
    std::sort(d.begin(), d.end());
    for(int i = 0; i < N; i++)
    {
        auto tlb = std::lower_bound(t.begin(), t.end(), stck[i].t) - t.begin();
        auto dlb = std::lower_bound(d.begin(), d.end(), stck[i].d) - d.begin();      
        ll tval = tdp[tlb];
        ll dval = ddp[dlb];
        tdp[tlb] = std::max(tdp[tlb], dval + abs(stck[i].d - stck[i].t) + L);
        ddp[dlb] = std::max(ddp[dlb], tval + abs(stck[i].d - stck[i].t) + L);
        ans = std::max(tdp[tlb], ans);
        ans = std::max(ddp[dlb], ans);
    }
    std::cout << ans << '\n';
    return 0;
}