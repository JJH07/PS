#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000
typedef long long ll;
ll n, m;
std::vector<ll> seat;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        ll s;
        std::cin >> s;
        seat.push_back(s);
    }
    std::sort(seat.begin(), seat.end());
    ll l = 0, r = seat.back() * m;
    while(l <= r)
    {
        ll mid = (l + r) >> 1;
        ll counting = 0;
        for(int i = 0; i < n; i++)
        {
            counting += mid / seat[i];
            if(counting > m)
            {
                break;
            }
        }
        if(counting >= m)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    std::cout << l << '\n';
    return 0;
}