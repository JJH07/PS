#include <iostream>
#define MAX 128
typedef std::pair<int, int> pii;
int n, map[MAX][MAX];
void PLUS(pii &a, pii b)
{
    a.first += b.first;
    a.second += b.second;
}
pii dfs(int x, int y, int sz)
{
    pii ret = {0, 0};
    int sum = 0;
    for(int i = x; i < x + sz; i++)
    {
        for(int j = y; j < y + sz; j++)
        {
            sum += map[i][j];
        }
    }
    if(sum == sz * sz)
    {
        return {0, 1};
    }
    if(sum == 0)
    {
        return {1, 0};
    }
    for(int i = 0; i < sz; i += sz / 2)
    {
        for(int j = 0; j < sz; j += sz / 2)
        {
            PLUS(ret, dfs(x + i, y + j, sz / 2));
        }
    }
    return ret;
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
            std::cin >> map[i][j];
        }
    }
    pii ans = dfs(0, 0, n);
    std::cout << ans.first << '\n' << ans.second << '\n';
    return 0;
}