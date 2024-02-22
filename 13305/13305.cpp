#include <bits/stdc++.h>
typedef long long ll;
typedef std::pair<ll, int> pli;
const ll MAX = 100000;

ll n, distance[MAX];
std::priority_queue<pli> pq;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        std::cin >> distance[i];
    }
    for(int i = 0; i < n; i++)
    {
        ll t;
        std::cin >> t;
        if(i < n - 1)
        {
            pq.push(std::make_pair(-t, i));
        }
    }
    int s = 0, e = n - 1;
    ll cost = 0;
    while(s != e && !pq.empty())
    {
        auto [price, idx] = pq.top();
        pq.pop();
        if(idx < s || e < idx)
        {
            continue;
        }
        ll d = 0;
        for(int i = idx; i < e; i++)
        {
            d += distance[i];
        }
        cost += d * -price;
        e = idx;
    }
    std::cout << cost << '\n';
    return 0;
}