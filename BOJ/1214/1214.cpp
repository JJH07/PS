#include <algorithm>
#include <climits>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long target, p, q;
    std::cin >> target >> p >> q;
    if(p > q)
    {
        std::swap(p, q);
    }
    long long best = LLONG_MAX;
    const long long limit = std::min(p, target / q + 2);
    for(long long countQ = 0; countQ < limit; countQ++)
    {
        const long long remaining = target - q * countQ;
        const long long countP = remaining > 0 ? (remaining + p - 1) / p : 0;
        const long long candidate = p * countP + q * countQ;
        best = std::min(best, candidate);
    }
    std::cout << best << '\n';
    return 0;
}
