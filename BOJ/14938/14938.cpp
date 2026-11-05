#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
int n, m, r, area[MAX], distance[MAX][MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::fill(distance[0], distance[0] + MAX * MAX, MAX * MAX);
    std::cin >> n >> m >> r;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> area[i];
    }
    for(int i = 0; i < r; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        distance[a][b] = c;
        distance[b][a] = c;   
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i != j)
                {
                    distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int item = area[i];
        for(int j = 1; j <= n; j++)
        {
            if(distance[i][j] <= m)
            {
                item += area[j];
            }
        }
        ans = std::max(ans, item);
    }
    std::cout << ans << '\n';
    return 0;
}