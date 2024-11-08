#include <bits/stdc++.h>

const int MAX = 21;
int n, map[MAX][MAX], sector[MAX][MAX], ans = INT_MAX;
int simulate(int x, int y, int d1, int d2)
{
    int _min = INT_MAX, _max = INT_MIN, p[6];
    std::memset(sector, 0, sizeof(sector));
    std::memset(p, 0, sizeof(p));

    for(int bx = x, by = y; by >= 1; by--)
    {
        for(int i = bx - 1; i >= 1; i--)
        {
            sector[i][by] = 1;
        }
        if(bx != x + d1)
        {
            bx++;
        }
    }
    for(int bx = x, by = y; by <= n - 1; by++)
    {
        for(int i = bx; i >= 1; i--)
        {
            sector[i][by + 1] = 2;
        }
        if(bx != x + d2)
        {
            bx++;
        }
    }
    for(int bx = x + d1, by = y - d1; bx <= n; bx++)
    {
        for(int i = 1; i < by; i++)
        {
            sector[bx][i] = 3;
        }
        if(by != y - d1 + d2)
        {
            by++;
        }
    }
    for(int bx = x + d2, by = y + d2; bx <= n - 1; bx++)
    {
        for(int i = by; i <= n; i++)
        {
            sector[bx + 1][i] = 4;
        }
        if(by != y + d2 - d1)
        {
            by--;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(sector[i][j] == 0)
            {
                p[5] += map[i][j];
            }
            else
            {
                p[sector[i][j]] += map[i][j];
            }
        }
    }
    for(int i = 1; i <= 5; i++)
    {
        _min = std::min(_min, p[i]);
        _max = std::max(_max, p[i]);
    }
    return _max - _min;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            std::cin >> map[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            for(int d1 = 1; j - d1 >= 1; d1++)
            {
                for(int d2 = 1; (i + d1 + d2) <= n && (j + d2) <= n; d2++)
                {
                    ans = std::min(ans, simulate(i, j, d1, d2));
                }
            }
        }
    }
    std::cout << ans << '\n';
    return 0;   
}