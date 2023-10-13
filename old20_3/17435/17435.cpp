#include <iostream>

int fnx[20][200001];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int m;
    std::cin >> m;
    for(int i = 1; i <= m; i++)
    {
        std::cin >> fnx[0][i];
    }
    for(int n = 1; n < 20; n++)
    {
        for(int x = 1; x <= m; x++)
        {
            fnx[n][x] = fnx[n - 1][fnx[n - 1][x]];
        }
    }
    int Q;
    std::cin >> Q;
    while(Q--)
    {
        int n, x;
        std::cin >> n >> x;
        for(int i = 0; n > 0; i++)
        {
            if(n % 2)
            {
                x = fnx[i][x];
            }
            n /= 2;
        }
        std::cout << x << '\n';
    }

    return 0;
}