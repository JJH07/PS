#include <iostream>
#include <cmath>
#define MAX_POINTS 20
typedef std::pair<int, int> Point;
int pointCount;
double minimumLength;
Point points[MAX_POINTS], totalSum, selectedSum;
Point operator+(const Point &a, const Point &b)
{
    return {a.first + b.first, a.second + b.second};
}
Point operator-(const Point &a, const Point &b)
{
    return {a.first - b.first, a.second - b.second};
}
double vectorLength(const Point &a)
{
    return sqrt(1LL * a.first * a.first + 1LL * a.second * a.second);
}
void choosePositivePoints(int selectedCount, int nextIndex, Point selectedSum)
{
    if(selectedCount == pointCount / 2)
    {
        minimumLength = std::min(minimumLength, vectorLength(selectedSum - (totalSum - selectedSum)));
    }
    else
    {
        for(int i = nextIndex; i < pointCount; i++)
        {
            choosePositivePoints(selectedCount + 1, i + 1, selectedSum + points[i]);
        }
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::fixed;
    std::cout.precision(12);
    int testCaseCount;
    std::cin >> testCaseCount;
    while(testCaseCount--)
    {
        totalSum = {0, 0};
        selectedSum = {0, 0};
        minimumLength = 1e9;
        std::cin >> pointCount;
        for(int i = 0; i < pointCount; i++)
        {
            std::cin >> points[i].first >> points[i].second;
            totalSum.first += points[i].first;
            totalSum.second += points[i].second;
        }
        choosePositivePoints(0, 0, {0, 0});
        std::cout << minimumLength << '\n';
    }
    return 0;
}