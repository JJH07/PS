#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
typedef long long ll;;
typedef std::pair<ll, ll> pll;
int n;
ll d;
std::vector<pll> list;
int solve()
{
    ll s = -100000000, e = -100000000 + d, ret = 0;
    std::priority_queue<pll> pq;
    for(auto [o, h] : list)
    {
        if(e < o)
        {
            ret = std::max(ret, (ll)pq.size());
            s = o - d;
            e = o;
            while(!pq.empty())
            {
                auto [l, r] = pq.top();
                if(s <= -l)
                {
                    break;
                }
                pq.pop();
            }
        }
        if(s <= h && o <= e)
        {
            pq.push({-h, -o});
        }
    }
    return std::max(ret, (ll)pq.size());
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll h, o;
        std::cin >> h >> o;
        if(h > o)
        {
            std::swap(h, o);
        }
        list.push_back({o, h});
    }
    std::cin >> d;
    std::sort(list.begin(), list.end());
    std::cout << solve() << '\n';
    return 0;
}