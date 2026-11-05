#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 1e18
typedef long long ll;
int check(std::vector<ll> &list, int s)
{
    ll sum = 0;
    int idx = 0;
    int sz = (int)list.size();
    for(int i = 0; i < sz; i++)
    {
        sum += list[i];
    }
    for(int i = 0, sum = 0; i < sz; i++)
    {
        sum += list[i];
        if(sum >= s)
        {
            idx = i;
            break;
        }
    }
    return (sum <= s ? -1 : idx);
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--)
    {
        ll n, t, s;
        std::vector<ll> list;
        std::cin >> n >> s;
        t = n;
        while(t > 0)
        {
            ll res = t % 10;
            list.push_back(res);
            t /= 10;
        }
        std::reverse(list.begin(), list.end());
        int idx = check(list, s);
        if(idx == -1)
        {
            std::cout << "0\n";
        }
        else
        {
            for(int i = idx; i < list.size(); i++)
            {
                list[i] = 0;
            }
            for(int i = idx - 1; i >= 0; i--)
            {
                if(list[i] == 9)
                {
                    list[i] = 0;
                }
                else
                {
                    list[i]++;
                    break;
                }
            }
            ll ans;
            if(list[0] == 0)
            {
                ans = 1;
            }
            else
            {
                ans = 0;
            }
            for(auto x : list)
            {
                ans = 1ll * 10 * ans + x;
            }
            std::cout << ans - n << '\n';
        }
    }
    return 0;
}