#include <iostream>
#include <cstring>
#include <vector>
const int MAX = 1001;

int n, m, k, d[MAX];
bool check[MAX];
std::vector<int> list[MAX];
bool dfs(int worker)
{
    for(auto x : list[worker])
    {
        if(check[x])
        {
            continue;
        }
        check[x] = 1;
        if(d[x] == 0 || dfs(d[x]))
        {
            d[x] = worker;
            return 1;
        }
    }
    return 0;
}
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
    {
        int c;
        scanf("%d", &c);
        for(int j = 0; j < c; j++)
        {
            int idx;
            scanf("%d", &idx);
            list[i].push_back(idx);
        }
    }
    int ans = 0, k_i = 0;
    for(int i = 1; i <= n; i++)
    {
        std::memset(check, 0, sizeof(check));
        if(dfs(i))
        {
            ans++;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(list[i].size() > 1)
        {
            std::memset(check, 0, sizeof(check));
            if(dfs(i))
            {
                k_i++;
                ans++;
            }
        }
        if(k_i == k)
        {
            break;
        }
    }
    std::cout << ans << '\n';
    return 0;
}