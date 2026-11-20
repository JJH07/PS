#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define VALUE_ARRAY_SIZE 1001

int valueCount, matchedEvenByOdd[VALUE_ARRAY_SIZE], matchedOddByEven[VALUE_ARRAY_SIZE];
bool isComposite[2001], visitedOdd[VALUE_ARRAY_SIZE];
std::vector<int> primeSumNeighbors[VALUE_ARRAY_SIZE];

bool tryMatchOdd(int oddValue)
{
    if(visitedOdd[oddValue])
    {
        return false;
    }
    visitedOdd[oddValue] = 1;
    for(auto &evenValue : primeSumNeighbors[oddValue])
    {
        if(matchedOddByEven[evenValue] == 0 || tryMatchOdd(matchedOddByEven[evenValue]))
        {
            matchedEvenByOdd[oddValue] = evenValue;
            matchedOddByEven[evenValue] = oddValue;
            return true;
        }
    }
    return false;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);

    for(int i = 2; i <= 2000; i++)
    {
        if(!isComposite[i])
        {
            for(int j = i + i; j <= 2000; j += i)
            {
                isComposite[j] = true;
            }
        }
    }

    int firstValue = 0;
    std::vector<int> oddValues, evenValues, possiblePartners;

    std::cin >> valueCount;
    for(int i = 0; i < valueCount; i++)
    {
        int value;
        std::cin >> value;
        if(i == 0)
        {
            firstValue = value;
        }
        if(value & 1)
        {
            oddValues.push_back(value);
        }
        else
        {
            evenValues.push_back(value);
        }
    }
    for(int i : oddValues)
    {
        for(int j : evenValues)
        {
            if(!isComposite[i + j])
            {
                primeSumNeighbors[i].push_back(j);
            }
        }
    }
    while(1)
    {
        std::memset(matchedEvenByOdd, 0, sizeof(matchedEvenByOdd));
        std::memset(matchedOddByEven, 0, sizeof(matchedOddByEven));
        int matchedPairCount = 0;
        for(auto oddValue : oddValues)
        {
            std::memset(visitedOdd, 0, sizeof(visitedOdd));
            if(tryMatchOdd(oddValue))
            {
                matchedPairCount++;
            }
        }
        if(matchedPairCount != valueCount / 2)
        {
            break;
        }
        if(firstValue & 1)
        {
            for(auto neighborIt = primeSumNeighbors[firstValue].begin(); neighborIt != primeSumNeighbors[firstValue].end(); neighborIt++)
            {
                if(*neighborIt == matchedEvenByOdd[firstValue])
                {
                    primeSumNeighbors[firstValue].erase(neighborIt);
                    break;
                }
            }
            possiblePartners.push_back(matchedEvenByOdd[firstValue]);
        }
        else
        {
            for(auto neighborIt = primeSumNeighbors[matchedOddByEven[firstValue]].begin(); neighborIt != primeSumNeighbors[matchedOddByEven[firstValue]].end(); neighborIt++)
            {
                if(*neighborIt == firstValue)
                {
                    primeSumNeighbors[matchedOddByEven[firstValue]].erase(neighborIt);
                    break;
                }
            }
            possiblePartners.push_back(matchedOddByEven[firstValue]);
        }
    }
    if(possiblePartners.empty())
    {
        std::cout << "-1\n";
    }
    else
    {
        std::sort(possiblePartners.begin(), possiblePartners.end());
        for(auto partner : possiblePartners)
        {
            std::cout << partner << ' ';
        }
    }
    return 0;
}
