#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define MAX 100001
int dx[3] = {-1, 1, 2};
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k, distance[MAX];
    std::priority_queue<std::pair<int, int>> pq;
    std::fill(distance, distance + MAX, MAX);

    std::cin >> n >> k;

    pq.push({0, n});
    distance[n] = 0;

    while(!pq.empty())
    {
        auto [dist, idx] = pq.top();
        pq.pop();
        if(distance[idx] < dist)
        {
            continue;
        }
        for(int i = 0; i < 3; i++)
        {
            int nx = idx + (i == 2 ? idx : dx[i]);
            if(nx < 0 || nx >= MAX)
            {
                continue;
            }
            int ndist = distance[idx] + (i == 2 ? 0 : 1);
            if(ndist < distance[nx])
            {
                distance[nx] = ndist;
                pq.push({-ndist, nx});
            }
        }
    }
    std::cout << distance[k] << '\n';
    return 0;
}