#include <iostream>
#include <climits>
#include <cmath>
typedef long long ll;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    ll D, P, Q;
    std::cin >> D >> P >> Q;
    if(P > Q)
    {
        std::swap(P, Q);
    }
    ll ans = LLONG_MAX;
    for(int Qi = 0; Qi < std::min(P, D / Q + 2); Qi++)
    {
        ll PMAX = (D - Q * Qi) / P;
        for(int Pi = std::max(1LL * 0, PMAX - 2); Pi < PMAX + 2; Pi++)
        {
            ll Candidate = P * Pi + Q * Qi;
            if(Candidate >= D)
            {
                ans = std::min(ans, Candidate);
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}