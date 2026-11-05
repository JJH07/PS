#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
#define INF 1000001
#define DEPTH 18
typedef std::pair<int, int> pii;
int n, level[MAX], Parent[MAX][DEPTH], Min[MAX][DEPTH], Max[MAX][DEPTH];
std::vector<pii> link[MAX];
void dfs(int now, int lv)
{
    for(auto [next, v] : link[now])
    {
        if(level[next] > 0)
        {
            continue;
        }
        level[next] = lv + 1;
        Parent[next][0] = now;
        Min[next][0] = v;
        Max[next][0] = v;
        dfs(next, lv + 1);
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::fill(Min[0], Min[0] + MAX * DEPTH, INF);
    std::cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        link[a].push_back({b, c});
        link[b].push_back({a, c});
    }
    level[1] = 1;
    dfs(1, 1);
    for(int j = 0; j < DEPTH - 1; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(Parent[i][j] > 0)
            {
                Min[i][j + 1] = std::min(Min[i][j], Min[Parent[i][j]][j]);
                Max[i][j + 1] = std::max(Max[i][j], Max[Parent[i][j]][j]);
                Parent[i][j + 1] = Parent[Parent[i][j]][j];
            }
        }
    }
    int k;
    std::cin >> k;
    while(k--)
    {
        int D, E, MN = INF, MX = 0;
        std::cin >> D >> E;
        if(level[D] > level[E])
        {
            std::swap(D, E);
        }
        int diff = level[E] - level[D];
        for(int i = 0; diff > 0; i++)
        {
            if(diff % 2)
            {
                MN = std::min(MN, Min[E][i]);
                MX = std::max(MX, Max[E][i]);
                E = Parent[E][i];
            }
            diff /= 2;
        }
        if(D != E)
        {
            for(int i = DEPTH - 1; i >= 0; i--)
            {
                if(Parent[D][i] > 0 && Parent[D][i] != Parent[E][i])
                {
                    MN = std::min({MN, Min[D][i], Min[E][i]});
                    MX = std::max({MX, Max[D][i], Max[E][i]});
                    D = Parent[D][i];
                    E = Parent[E][i];
                }
            }
            MN = std::min({MN, Min[D][0], Min[E][0]});
            MX = std::max({MX, Max[D][0], Max[E][0]});
        }
        std::cout << MN << ' ' << MX << '\n';
    }
    return 0;
}