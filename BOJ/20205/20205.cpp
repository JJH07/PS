#include <iostream>
#define MAX 100

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k, Expand[MAX][MAX];
    std::cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int t;
            std::cin >> t;
            for(int x = i * k; x < (i + 1) * k; x++)
            {
                for(int y = j * k; y < (j + 1) * k; y++)
                {
                    Expand[x][y] = t;
                }
            }
        }
    }
    for(int i = 0; i < n * k; i++)
    {
        for(int j = 0; j < n * k; j++)
        {
            std::cout << Expand[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}