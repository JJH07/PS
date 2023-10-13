#include <iostream>
#include <algorithm>
#define MAX 15
int n, ans, chess[MAX][MAX];
int dfs(int idx)
{
    if(idx == n)
    {
        return 1;
    }
    int ret = 0;
    for(int i = 0; i < n; i++)
    {
        if(chess[idx][i] > 0)
        {
            continue;
        }
        for(int down = 1; down < n - idx; down++)
        {
            chess[idx + down][i]++;
            if(i - down >= 0)
            {
                chess[idx + down][i - down]++;
            }
            if(i + down < n)
            {
                chess[idx + down][i + down]++;
            }
        }
        ret += dfs(idx + 1);
        for(int down = 1; down < n - idx; down++)
        {
            chess[idx + down][i]--;
            if(i - down >= 0)
            {
                chess[idx + down][i - down]--;
            }
            if(i + down < n)
            {
                chess[idx + down][i + down]--;
            }
        }
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    std::cout << dfs(0) << '\n';
    return 0;
}