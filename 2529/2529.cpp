#include <iostream>
#include <cstring>
#define INF 1e16
typedef long long ll;
int n;
char c[10];
ll Min = INF, Max;
void dfs(ll now, int before, int idx, int state)
{
    if(idx == n)
    {
        Min = std::min(Min, now);
        Max = std::max(Max, now);
        return ;
    }
    int s, e;
    if(c[idx] == '<')
    {
        s = before + 1, e = 10;
    }
    else
    {
        s = 0, e = before;
    }
    for(int i = s; i < e; i++)
    {
        if(state & (1 << i))
        {
            continue;
        }
        dfs(now * 10 + i, i, idx + 1, state + (1 << i));
    }
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> c[i];
    }
    for(int i = 0; i < 10; i++)
    {
        dfs(i, i, 0, 1 << i);
    }
    std::cout << Max << '\n';
    int less = 1;
    for(int i = 0; i < n; i++)
    {
        less *= 10;
    }
    if(Min < less)
    {
        std::cout << '0';
    }
    std::cout << Min;
    return 0;
}