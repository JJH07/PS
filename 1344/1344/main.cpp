//
//  main.cpp
//  1344
//
//  Created by 진준호 on 2020/02/11.
//  Copyright © 2020 진준호. All rights reserved.
//

#include <iostream>
#include <cmath>

double a, b, dp[19][19][19], ans;

bool is_prime(int num)
{
    if(num == 2 || num == 3 || num == 5 || num == 7 || num == 11 || num == 13 || num == 17)
    {
        return true;
    }
    return false;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::cin >> a >> b;

    a /= 100.0;
    b /= 100.0;
    
    dp[1][0][0] = (1 - a) * (1 - b);
    dp[1][1][0] = a * (1 - b);
    dp[1][0][1] = (1 - a) * b;
    dp[1][1][1] = a * b;
    for(int i = 2; i <= 18; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            for(int k = 0; k <= i; k++)
            {
                if(j > 0)
                {
                    dp[i][j][k] += dp[i-1][j-1][k] * a * (1 - b);
                }
                if(k > 0)
                {
                    dp[i][j][k] += dp[i-1][j][k-1] * (1 - a) * b;
                }
                if(j > 0 && k > 0)
                {
                    dp[i][j][k] += dp[i-1][j-1][k-1] * a * b;
                }
                dp[i][j][k] += dp[i-1][j][k] * (1 - a) * (1 - b);
            }
        }
    }
    for(int i = 0; i < 19; i++)
    {
        for(int j = 0; j < 19; j++)
        {
            if(is_prime(i) || is_prime(j))
            {
                ans += dp[18][i][j];
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}
