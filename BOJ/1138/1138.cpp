// Copyright © 2020 진준호. All rights reserved.

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, lineup[11]{};
    std::cin >> n;
    for(int height = 1; height <= n; height++)
    {
        int toSkip;
        std::cin >> toSkip;
        for(int pos = 1; pos <= n; pos++)
        {
            if(lineup[pos] != 0)
            {
                continue;
            }
            if(toSkip == 0)
            {
                lineup[pos] = height;
                break;
            }
            toSkip--;
        }
    }
    for(int pos = 1; pos <= n; pos++)
    {
        std::cout << lineup[pos] << (pos == n ? '\n' : ' ');
    }
    return 0;
}
