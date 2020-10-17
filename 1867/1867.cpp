#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define MAX 501

int n, k, d[MAX];
bool check[MAX];
std::vector<int> Y[MAX];
bool dfs(int x)
{
    if(check[x])
    {
        return false;
    }
    check[x] = true;
    for(int y : Y[x])
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

    std::cin >> n >> k;
    for(int i = 0; i < k; i++)
    {
        int a, b;
        std::cin >> a >> b;
        Y[a].push_back(b);
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