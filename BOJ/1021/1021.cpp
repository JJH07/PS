#include <iostream>
#include <queue>
int rotateAndRemove(std::deque<int> &values, int targetValue)
{
    int queueSize = (int)values.size();
    int targetIndex;
    for(targetIndex = 0; targetIndex < queueSize; targetIndex++)
    {
        if(values[targetIndex] == targetValue)
        {
            break;
        }
    }
    int rotationCount = std::min(targetIndex, queueSize - targetIndex);
    for(int i = 0; i < rotationCount; i++)
    {
        if(targetIndex < queueSize - targetIndex)
        {
            values.push_back(values.front());
            values.pop_front();
        }
        else
        {
            values.push_front(values.back());
            values.pop_back();
        }
    }
    values.pop_front();
    return rotationCount;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int initialSize, targetCount, totalRotations = 0;
    std::deque<int> values;
    std::cin >> initialSize >> targetCount;
    for(int i = 1; i <= initialSize; i++)
    {
        values.push_back(i);
    }
    while(targetCount--)
    {
        int targetValue;
        std::cin >> targetValue;
        totalRotations += rotateAndRemove(values, targetValue);
    }   
    std::cout << totalRotations << '\n';
    return 0;
}