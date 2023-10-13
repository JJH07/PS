#include <iostream>
#include <cstring>
#include <vector>
const int MAX = 1000;

int n, m, check[MAX + 1], work[MAX + 1];
std::vector<int> worktable[MAX + 1];

int dfs(int worker)
{
    for(int w : worktable[worker])
    {
        if(check[w])
        {
            continue;
        }
        check[w] = 1;
        if(work[w] == 0 || dfs(work[w]))
        {
            work[w] = worker;
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
            worktable[i].push_back(idx);
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        std::memset(check, 0, sizeof(check));
        cnt += dfs(i);
    }
    std::cout << cnt << '\n';
    return 0;
}