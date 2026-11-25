// Copyright © 2020 진준호. All rights reserved.

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, dist[21][21], totalWeight = 0;

    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cin >> dist[i][j];
        }
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(i == k || dist[i][k] == 0)
            {
                continue;
            }
            for(int j = 1; j <= n; j++)
            {
                if(k == j || i == j || dist[k][j] == 0)
                {
                    continue;
                }
                const int via = dist[i][k] + dist[k][j];
                if(dist[i][j] > via)
                {
                    std::cout << "-1\n";
                    return 0;
                }
                if(via == dist[i][j])
                {
                    dist[i][j] = 0;
                }

            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            totalWeight += dist[i][j];
        }
    }
    std::cout << totalWeight / 2 << '\n';
    return 0;
}
