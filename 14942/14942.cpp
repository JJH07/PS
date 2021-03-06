#include <iostream>
#include <vector>
#define MAX 100001
#define DEPTH 17
typedef std::pair<int, int> pii;
int n, Ants[MAX], Parent[MAX][DEPTH], Distance[MAX][DEPTH];
bool visited[MAX];
std::vector<pii> link[MAX];
void dfs(int now)
{
    for(auto [next, v] : link[now])
    {
        if(!visited[next])
        {
            Parent[next][0] = now;
            Distance[next][0] = v;
            visited[next] = true;
            dfs(next);
        }
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> Ants[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        link[a].push_back({b, c});
        link[b].push_back({a, c});
    }
    visited[1] = true;
    dfs(1);
    for(int j = 0; j < DEPTH - 1; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(Parent[i][j] > 0)
            {
                Parent[i][j + 1] = Parent[Parent[i][j]][j];
                Distance[i][j + 1] = Distance[i][j] + Distance[Parent[i][j]][j];
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        int pos = i, Energy = Ants[i];
        for(int j = DEPTH - 1; j >= 0 && Energy > 0; j--)
        {
            if(Parent[pos][j] > 0 && Energy >= Distance[pos][j])
            {
                Energy -= Distance[pos][j];
                pos = Parent[pos][j];
            }
        }
        std::cout << pos << '\n';
    }
    return 0;
}