//  Copyright © 2020 진준호. All rights reserved.

#include <iostream>

int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n, type = 1, factorial[21], rank, used[21];

    factorial[0] = 1;
    for(int i = 1; i <= 20; i++)
    {
        factorial[i] = factorial[i-1] * i;
    }
    for(int i = 1; i <= 21; i++)
    {
        used[i] = 0;
    }

    std::cin >> n >> type;
    if(type == 1)
    {
        std::cin >> rank;
        for(int i = 1; i <= n; i++)
        {
            const long long block = factorial[n - i];
            for(int j = 1; j <= n; j++)
            {
                if(used[j] == 1)
                {
                    continue;
                }
                if(rank <= block)
                {
                    std::cout << j << ' ';
                    used[j] = 1;
                    break;
                }
                rank -= block;
            }
        }
    }
    else
    {
        rank = 1;
        for(int i = 1; i <= n; i++)
        {
            const long long block = factorial[n - i];
            int value;
            std::cin >> value;
            for(int j = 1; j < value; j++)
            {
                if(used[j] == 1)
                {
                    continue;
                }
                rank += block;
            }
            used[value] = 1;
        }
        std::cout << rank;
    }
    std::cout << '\n';
    return 0;
}
