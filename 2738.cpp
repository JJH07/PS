#include <bits/stdc++.h>
const int MAX = 101;
int map[MAX][MAX];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int t;
            std::cin >> t;
            map[i][j] += t;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int t;
            std::cin >> t;
            map[i][j] += t;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cout << map[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}