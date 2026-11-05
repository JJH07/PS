#include <iostream>
#include <cstring>
#define MAX 1000001
bool isPrime[MAX];
int table[100][100], n;
bool dfs_R(int x, int y, int sum)
{
    if(y == n)
    {
        return !isPrime[sum];
    }
    if(table[x][y] != 0)
    {
        return dfs_R(x, y + 1, sum + table[x][y]);
    }
    for(int i = 1; i < MAX; i++)
    {
        if(!isPrime[i])
        {
            continue;
        }
        table[x][y] = i;
        if(dfs_R(x, y + 1, sum + i))
        {
            return true;
        }
        table[x][y] = 0;
    }
    return false;
}
bool dfs_D(int x, int y, int sum)
{
    if(x == n)
    {
        return !isPrime[sum];
    }
    if(table[x][y] != 0)
    {
        return dfs_D(x + 1, y, sum + table[x][y]);
    }
    for(int i = 1; i < MAX; i++)
    {
        if(!isPrime[i])
        {
            continue;
        }
        table[x][y] = i;
        if(dfs_D(x + 1, y, sum + i))
        {
            return true;
        }
        table[x][y] = 0;
    }
    return false;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    isPrime[1] = true;
    for(int i = 2; i < MAX; i++)
    {
        if(!isPrime[i])
        {
            for(int j = i + i; j < MAX; j += i)
            {
                isPrime[j] = true;
            }
        }
    }
    int t;
    std::cin >> t;
    while(t--)
    {
        std::memset(table, 0, sizeof(table));
        std::cin >> n;
        for(int i = 0; i < n - 1; i++)
        {
            dfs_R(i, 0, 0);
            dfs_D(0, i, 0);
        }
        int R = 0, D = 0;
        for(int i = 0; i < n - 1; i++)
        {
            R += table[n - 1][i];
            D += table[i][n - 1];
        }
        for(int i = 1; i < MAX; i++)
        {
            if(isPrime[i] && !isPrime[i + R] && !isPrime[i + D])
            {
                table[n - 1][n - 1] = i;
                break;
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                std::cout << table[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }
    return 0;
}