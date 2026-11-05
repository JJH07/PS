#include <iostream>
#include <vector>
#include <cstring>
#define MAX 201

int n, m, k, d[MAX];
bool map[MAX][MAX], check[MAX];
std::vector<int> link[MAX];
bool dfs(int x)
{
    if(check[x])
    {
        return false;
    }
    check[x] = true;
    for(auto y : link[x])
    {
        if(d[y] == 0 || dfs(d[y]))
        {
            d[y] = x;
            return true;
        }
    }
    return false;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m >> k;
    for(int i = 0; i < k; i++)
    {
        int x, y;
        std::cin >> x >> y;
        link[x].push_back(y);
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
    std::cout << n + m - ans << '\n';
    return 0;
}