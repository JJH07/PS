#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAX 10
typedef std::pair<int, int> pii;
int n, m, h, distance[MAX + 1][MAX + 1], ans;
std::vector<pii> list(1);
void make_distance()
{
    for(int i = 0; i < (int)list.size(); i++)
    {
        for(int j = 0; j < (int)list.size(); j++)
        {
            distance[i][j] = abs(list[i].first - list[j].first) + abs(list[i].second - list[j].second);
        }
    }
}
void dfs(int now, int hp, int drunk, int visited)
{
    if(distance[now][0] <= hp)
    {
        ans = std::max(ans, drunk);
    }
    int sz = (int)list.size();
    for(int i = 1; i < sz; i++)
    {
        if(visited & (1 << i))
        {
            continue;
        }
        if(hp >= distance[now][i])
        {
            dfs(i, hp - distance[now][i] + h, drunk + 1, visited + (1 << i));
        }
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> n >> m >> h;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int t;
            std::cin >> t;
            if(t == 1)
            {
                list[0].first = i;
                list[0].second = j;
            }
            if(t == 2)
            {
                list.push_back({i, j});
            }
        }
    }
    make_distance();
    dfs(0, m, 0, 0);
    std::cout << ans << '\n';
    return 0;
}