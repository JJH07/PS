#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int elementCount;
    std::cin >> elementCount;
    std::vector<int> values(elementCount), sortedWeights(elementCount);
    for(int &value : values)
    {
        std::cin >> value;
    }
    for(int &weight : sortedWeights)
    {
        std::cin >> weight;
    }
    std::sort(values.begin(), values.end());
    std::sort(sortedWeights.begin(), sortedWeights.end(), std::greater<int>());

    int minimumSum = 0;
    for(int index = 0; index < elementCount; index++)
    {
        minimumSum += values[index] * sortedWeights[index];
    }
    std::cout << minimumSum << '\n';
    return 0;
}
