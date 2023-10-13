#include <iostream>
#define MAX 101
int n, m;
bool map[MAX][MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int b, s;
        std::cin >> b >> s;
        map[b][s] = true;
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i == j)
                {
                    continue;
                }
                if(map[i][k] && map[k][j])
                {
                    map[i][j] = true;
                }
            }
        }
    }
    for(int s = 1; s <= n; s++)
    {
        int cnt = 1;
        for(int e = 1; e <= n; e++)
        {
            cnt += map[s][e] + map[e][s];
        }
        std::cout << n - cnt << '\n';
    }
    return 0;
}