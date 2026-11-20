#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int artistCount, maskCount, salePrices[15][15];
std::vector<int> additionalOwnersMemo;

int maxAdditionalOwners(int owner, int lastPrice, int visitedMask)
{
    const int memoIndex = (owner * 10 + lastPrice) * maskCount + visitedMask;
    int &cachedMaximum = additionalOwnersMemo[memoIndex];
    if(cachedMaximum != -1)
    {
        return cachedMaximum;
    }
    cachedMaximum = 0;
    for(int buyer = 0; buyer < artistCount; buyer++)
    {
        const int buyerBit = 1 << buyer;
        if((visitedMask & buyerBit) || salePrices[owner][buyer] < lastPrice)
        {
            continue;
        }
        cachedMaximum = std::max(
            cachedMaximum,
            1 + maxAdditionalOwners(buyer, salePrices[owner][buyer], visitedMask | buyerBit));
    }
    return cachedMaximum;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> artistCount;
    maskCount = 1 << artistCount;
    additionalOwnersMemo.assign(artistCount * 10 * maskCount, -1);
    for(int seller = 0; seller < artistCount; seller++)
    {
        std::string priceRow;
        std::cin >> priceRow;
        for(int buyer = 0; buyer < artistCount; buyer++)
        {
            salePrices[seller][buyer] = priceRow[buyer] - '0';
        }
    }
    std::cout << 1 + maxAdditionalOwners(0, 0, 1) << '\n';
    return 0;
}
