#include <bits/stdc++.h>
typedef long long ll;
int nonsqrt[1000001];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    ll mn, mx, ans = 0;
    std::cin >> mn >> mx;
    
    for(ll c = 2; c * c <= mx; c++)
    {
        ll len = mx / (c * c);
        for(long long p = mn / (c * c); p <= len; p++)
        {
            ll val = p * (c * c);
            if(val >= mn && val <= mx)
            {
                nonsqrt[val - mn] = true;
            }
        }
    }
    for(int i = 0; i < mx - mn + 1; i++)
    {
        if(nonsqrt[i] == 0)
        {
            ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}
