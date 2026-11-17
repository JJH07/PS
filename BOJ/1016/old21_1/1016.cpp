#include <iostream>
#define MOBIUS_LIMIT 1000100
typedef long long ll;
ll mobius[MOBIUS_LIMIT];
void initializeMobius()
{
    mobius[1] = 1;
    for(int divisor = 1; divisor < MOBIUS_LIMIT; divisor++)
    {
        for(int multiple = 2 * divisor; multiple < MOBIUS_LIMIT; multiple += divisor)
        {
            mobius[multiple] -= mobius[divisor];
        }
    }
}
ll countSquareFreeUpTo(ll upperBound)
{
    ll squareFreeCount = 0;
    for(ll divisor = 1; divisor * divisor <= upperBound; divisor++)
    {
        squareFreeCount += mobius[divisor] * (upperBound / (divisor * divisor));
    }
    return squareFreeCount;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    initializeMobius();
    ll rangeStart, rangeEnd;
    std::cin >> rangeStart >> rangeEnd;
    std::cout << countSquareFreeUpTo(rangeEnd) - countSquareFreeUpTo(rangeStart - 1) << '\n';
    return 0;
}