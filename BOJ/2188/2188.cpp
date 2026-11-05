#include <iostream>
#include <vector>

int n, m, status[201], check[201];
std::vector<int> link[201];

int dfs(int cow)
{
    for(int house : link[cow])
    {
        if(check[house])
        {
            continue;
        }
        check[house] = 1;
        if(status[house] == 0 || dfs(status[house]))
        {
            status[house] = cow;
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
    for(int i = 1; i <= n; i++)
    {
        int c;
        std::cin >> c;
        for(int j = 0; j < c; j++)
        {
            int idx;
            std::cin >> idx;
            link[i].push_back(idx);
        }
    }
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        std::memset(check, 0, sizeof(check));
        count += dfs(i);
    }
    std::cout << count << '\n';
    return 0;
}