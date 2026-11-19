#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

int buildTime[1001], completionTime[1001];
std::vector<int> prerequisites[1001];
int getCompletionTime(int buildingId)
{
    int &cachedTime = completionTime[buildingId];
    if(cachedTime != -1)
    {
        return cachedTime;
    }
    cachedTime = buildTime[buildingId];
    for(auto prerequisiteId : prerequisites[buildingId])
    {
        cachedTime = std::max(cachedTime, buildTime[buildingId] + getCompletionTime(prerequisiteId));
    }
    return cachedTime;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testCaseCount;
    std::cin >> testCaseCount;
    while(testCaseCount--)
    {
        int buildingCount, ruleCount, targetBuilding;
        std::cin >> buildingCount >> ruleCount;

        for(int i = 1; i <= buildingCount; i++)
        {
            prerequisites[i].clear();
        }
        std::memset(completionTime, -1, sizeof(completionTime));

        for(int i = 1; i <= buildingCount; i++)
        {
            std::cin >> buildTime[i];
        }
        for(int i = 0; i < ruleCount; i++)
        {
            int prerequisiteBuilding, dependentBuilding;
            std::cin >> prerequisiteBuilding >> dependentBuilding;
            prerequisites[dependentBuilding].push_back(prerequisiteBuilding);
        }
        std::cin >> targetBuilding;
        std::cout << getCompletionTime(targetBuilding) << '\n';
    }
    return 0;
}
