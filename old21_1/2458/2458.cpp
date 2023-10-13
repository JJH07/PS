#include <iostream>
#include <vector>
#include <cstring>
#define MAX 501
int n, m;
bool link[MAX][MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        link[a][b] = true;
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(link[i][j])
                {
                    continue;
                }
                if(link[i][k] && link[k][j])
                {   
                    link[i][j] = true;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int count = 0;
        for(int j = 1; j <= n; j++)
        {
            if(link[i][j])
            {
                count++;
            }
            if(link[j][i])
            {
                count++;
            }
        }
        if(count == n - 1)
        {
            ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}