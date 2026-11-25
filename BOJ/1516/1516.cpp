#include <algorithm>
#include <iostream>
#include <vector>
constexpr int MAX = 501;
int n, buildTime[MAX], finishTime[MAX];
std::vector<int> prerequisites[MAX];
int finishAt(int node)
{
    if(finishTime[node] > 0)
    {
        return finishTime[node];
    }
    int waitTime = 0;
    for(auto p : prerequisites[node])
    {
        waitTime = std::max(waitTime, finishAt(p));
    }
    return finishTime[node] = waitTime + buildTime[node];
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> buildTime[i];
        while(1)
        {
            int prerequisite;
            std::cin >> prerequisite;
            if(prerequisite == -1)
            {
                break;
            }
            prerequisites[i].push_back(prerequisite);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        std::cout << finishAt(i) << '\n';
    }
    return 0;
}
