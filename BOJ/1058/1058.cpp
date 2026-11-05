#include <iostream>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, map[50][50];
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char c;
            std::cin >> c;
            if(c == 'N')
            {
                map[i][j] = 0;
            }
            else
            {
                map[i][j] = 1;
            }
        }
    }
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j || map[i][k] == 0 || map[k][j] == 0)
                {
                    continue;
                }
                map[i][j] = std::min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int t = 0;
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                continue;
            }
            if(map[i][j] <= 2)
            {
                t++;
            }
        }
        ans = std::max(ans, t);
    }
    std::cout << ans << '\n';
    return 0;
}