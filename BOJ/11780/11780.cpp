#include <bits/stdc++.h>
const int MAX = 101;
const int INF = 1000000;
int n, m, map[MAX][MAX];
std::vector<int> mid[MAX][MAX];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            map[i][j] = INF;
        }
    }

    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        map[a][b] = std::min(map[a][b], c);
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(i == k)
            {
                continue;
            }
            for(int j = 1; j <= n; j++)
            {
                if(i == j || j == k)
                {
                    continue;
                }
                if(map[i][j] > map[i][k] + map[k][j])
                {
                    map[i][j] = map[i][k] + map[k][j];
                    mid[i][j] = mid[i][k];
                    mid[i][j].push_back(k);
                    for(int x : mid[k][j])
                    {
                        mid[i][j].push_back(x);
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cout << (map[i][j] == INF ? 0 : map[i][j]) << ' ';
        }
        std::cout << '\n';
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j  = 1; j <= n; j++)
        {
            if(map[i][j] == INF)
            {
                std::cout << "0\n";
            }
            else
            {
                std::cout << 2 + mid[i][j].size() << ' ' << i << ' ';
                for(int x : mid[i][j])
                {
                    std::cout << x << ' ';
                }
                std::cout << j << '\n';
            }
        }
    }
    return 0;
}
