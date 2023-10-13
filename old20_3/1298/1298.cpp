#include <iostream>
#include <cstring>
#include <vector>
const int MAX = 101;

int n, m, d[MAX];
std::vector<int> list[MAX];
bool check[MAX];
bool dfs(int person)
{
    for(int notebook : list[person])
    {
        if(check[notebook])
        {
            continue;
        }
        check[notebook] = 1;
        if(d[notebook] == 0 || dfs(d[notebook]))
        {
            d[notebook] = person;
            return 1;
        }
    }
    return 0;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        list[a].push_back(b);
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