#include <iostream>
#include <algorithm>
#include <vector>
#define INF (int)1e9
#define MAX 51
int map[MAX][MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::fill(map[0], map[0] + MAX * MAX, INF);

    int n;
    std::cin >> n;
    while(1)
    {
        int a, b;
        std::cin >> a >> b;
        if(a == -1 && b == -1)
        {
            break;
        }
        map[a][b] = 1;
        map[b][a] = 1;
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i == j || map[i][k] == INF || map[k][j] == INF)
                {
                    continue;
                }
                map[i][j] = std::min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    int point = INF;
    std::vector<int> ans;
    for(int i = 1; i <= n; i++)
    {
        int now = 0;
        for(int j = 1; j <= n; j++)
        {
            if(map[i][j] == INF)
            {
                continue;
            }
            now = std::max(now, map[i][j]);
        }
        if(point > now)
        {
            ans.clear();
            point = now;
        }
        if(point == now)
        {
            ans.push_back(i);
        }
    }
    std::sort(ans.begin(), ans.end());
    std::cout << point << ' ' << ans.size() << '\n';
    for(auto x : ans)
    {
        std::cout << x << ' ';
    }
    return 0;
}