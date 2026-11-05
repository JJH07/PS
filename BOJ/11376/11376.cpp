#include <iostream>
#include <cstring>
#include <vector>

int n, m, d[1001];
bool check[1001];
std::vector<int> worklist[1001];

int dfs(int worker)
{
    for(int w : worklist[worker])
    {
        if(check[w])
        {
            continue;
        }
        check[w] = 1;
        if(d[w] == 0 || dfs(d[w]))
        {
            d[w] = worker;
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
            worklist[i].push_back(idx);
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        std::memset(check, 0, sizeof(check));
        cnt += dfs(i);   
        std::memset(check, 0, sizeof(check));
        cnt += dfs(i);
    }
    std::cout << cnt << '\n';
    return 0;
}