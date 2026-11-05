#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 201
int n, m, Color[MAX];
bool check[MAX];
std::vector<int> link[MAX];
bool dfs(int T)
{
    for(auto C : link[T])
    {
        if(check[C])
        {
            continue;
        }
        check[C] = true;
        if(Color[C] == 0 || dfs(Color[C]))
        {
            Color[C] = T;
            return true;
        }
    }
    return false;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int T_shirts[MAX];
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        std::cin >> T_shirts[i];
    }
    for(int i = 1; i <= m; i++)
    {
        int temp;
        std::cin >> temp;
        for(int T_idx = 1; T_idx <= n; T_idx++)
        {
            int w = T_shirts[T_idx];
            if((w <= 2 * temp && temp * 4 <= w * 3) || (w <= temp && temp * 4 <= w * 5))
            {
                link[T_idx].push_back(i);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        std::memset(check, 0, sizeof(check));
        if(dfs(i))
        {
            ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}