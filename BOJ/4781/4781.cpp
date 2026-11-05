//
//  main.cpp
//  4781
//
//  Created by 진준호 on 2020/03/01.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m;
    double d;
    int c[5001];
    int p[5001];
    int dp[10001];

    while (true)
    {
        memset(c, 0, sizeof(c));
        memset(p, 0, sizeof(p));
        memset(dp, 0, sizeof(dp));

        std::cin >> n >> d;
        m = (int)(d * 100 + 0.5);

        if (n == 0 && m == 0)
        {
            break;
        }

        for (int i = 1; i <= n; i++)
        {
            std::cin >> c[i] >> d;
            p[i] = (int)(d * 100 + 0.5);
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = p[i]; j <= m; j++)
            {
                dp[j] = max(dp[j], dp[j - p[i]] + c[i]);
            }
        }
        int ans = 0;
        for (int i = 0; i <= m; i++)
        {
            ans = max(ans, dp[i]);
        }

        std::cout << ans << '\n';
    }
    return 0;
}
