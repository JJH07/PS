#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
typedef long long ll;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::priority_queue<ll, std::vector<ll>, std::greater<ll>> pq;
    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        ll number;
        std::cin >> number;
        pq.push(number);
    }
    while(m--)
    {
        ll x = pq.top();
        pq.pop();
        ll y = pq.top();
        pq.pop();
        x = x + y;
        pq.push(x);
        pq.push(x);
    }
    ll ans = 0;
    while(!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    std::cout << ans << '\n';
    return 0;
}