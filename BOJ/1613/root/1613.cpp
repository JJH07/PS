
#include <bits/stdc++.h>
#define MAX 401

int map[MAX][MAX], n, k, s;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int pre, post;

    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if(i == j)
            {
                map[i][j] = 0;
            }
            else
            {
                map[i][j] = MAX;
            }
        }
    }
    std::cin >> n >> k;
    for(int i = 0; i < k; i++)
    {
        std::cin >> pre >> post;
        map[pre][post] = 1;
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                map[i][j] = std::min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    std::cin >> s;
    for(int i = 0; i < s; i++)
    {
        std::cin >> pre >> post;
        if(map[pre][post] == MAX && map[post][pre] == MAX)
        {
            std::cout << "0\n";
        }
        else if(map[pre][post] == MAX)
        {
            std::cout << "1\n";
        }
        else
        {
            std::cout << "-1\n";
        }
    }
    return 0;
}