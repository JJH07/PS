#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int minStops(const std::vector<std::pair<int, int>> &stations, int target, int reach)
{
    std::priority_queue<int> fuel;
    std::size_t next = 0;
    int stops = 0;
    while(reach < target)
    {
        while(next < stations.size() && stations[next].first <= reach)
        {
            fuel.push(stations[next].second);
            next++;
        }
        if(fuel.empty())
        {
            return -1;
        }
        reach += fuel.top();
        fuel.pop();
        stops++;
    }
    return stops;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> stations(n);
    for(auto &[pos, fuel] : stations)
    {
        std::cin >> pos >> fuel;
    }
    std::sort(stations.begin(), stations.end());
    int target, reach;
    std::cin >> target >> reach;
    std::cout << minStops(stations, target, reach) << '\n';
    return 0;
}
