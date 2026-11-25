#include <algorithm>
#include <iostream>

constexpr int MAX_N = 400;
constexpr int INF = MAX_N + 1;
int dist[MAX_N + 1][MAX_N + 1];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for(int i = 0; i <= MAX_N; i++)
    {
        for(int j = 0; j <= MAX_N; j++)
        {
            dist[i][j] = i == j ? 0 : INF;
        }
    }
    int n, k, queries;
    std::cin >> n >> k;
    for(int i = 0; i < k; i++)
    {
        int before, after;
        std::cin >> before >> after;
        dist[before][after] = 1;
    }
    for(int mid = 1; mid <= n; mid++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dist[i][j] = std::min(dist[i][j], dist[i][mid] + dist[mid][j]);
            }
        }
    }
    std::cin >> queries;
    for(int i = 0; i < queries; i++)
    {
        int before, after;
        std::cin >> before >> after;
        if(dist[before][after] == INF && dist[after][before] == INF)
        {
            std::cout << "0\n";
        }
        else if(dist[before][after] == INF)
        {
            std::cout << "1\n";
        }
        else
        {
            std::cout << "-1\n";
        }
    }
    return 0;
}
