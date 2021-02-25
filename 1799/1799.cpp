#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 20
typedef std::pair<int, int> pii;
int n, d[MAX];
bool check[MAX];
std::vector<int> link[MAX];
bool dfs(int X)
{
    if(check[X])
    {
        return false;
    }
    check[X] = true;
    for(auto Y : link[X])
    {
        if(d[Y] == 0 || dfs(d[Y]))
        {
            d[Y] = X;
            return true;
        }
    }
    return false;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int pos;
            std::cin >> pos;
            if(pos == 1)
            {
                link[i + j + 1].push_back(5 - i + j);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < MAX; i++)
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