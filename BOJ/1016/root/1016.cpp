#include <bits/stdc++.h>
typedef long long ll;
int hasSquareFactor[1000001];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    ll rangeStart, rangeEnd, squareFreeCount = 0;
    std::cin >> rangeStart >> rangeEnd;
    
    for(ll divisor = 2; divisor * divisor <= rangeEnd; divisor++)
    {
        ll lastMultipleIndex = rangeEnd / (divisor * divisor);
        for(long long multipleIndex = rangeStart / (divisor * divisor); multipleIndex <= lastMultipleIndex; multipleIndex++)
        {
            ll multipleValue = multipleIndex * (divisor * divisor);
            if(multipleValue >= rangeStart && multipleValue <= rangeEnd)
            {
                hasSquareFactor[multipleValue - rangeStart] = true;
            }
        }
    }
    for(int i = 0; i < rangeEnd - rangeStart + 1; i++)
    {
        if(hasSquareFactor[i] == 0)
        {
            squareFreeCount++;
        }
    }
    std::cout << squareFreeCount << '\n';
    return 0;
}
