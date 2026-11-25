// Copyright © 2020 진준호. All rights reserved.

#include <iostream>

double probA, probB, dp[19][19][19], answer;

bool isPrime(int num)
{
    if(num == 2 || num == 3 || num == 5 || num == 7 || num == 11 || num == 13 || num == 17)
    {
        return true;
    }
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> probA >> probB;

    probA /= 100.0;
    probB /= 100.0;

    dp[1][0][0] = (1 - probA) * (1 - probB);
    dp[1][1][0] = probA * (1 - probB);
    dp[1][0][1] = (1 - probA) * probB;
    dp[1][1][1] = probA * probB;
    for(int round = 2; round <= 18; round++)
    {
        for(int goalsA = 0; goalsA <= round; goalsA++)
        {
            for(int goalsB = 0; goalsB <= round; goalsB++)
            {
                if(goalsA > 0)
                {
                    dp[round][goalsA][goalsB] += dp[round-1][goalsA-1][goalsB] * probA * (1 - probB);
                }
                if(goalsB > 0)
                {
                    dp[round][goalsA][goalsB] += dp[round-1][goalsA][goalsB-1] * (1 - probA) * probB;
                }
                if(goalsA > 0 && goalsB > 0)
                {
                    dp[round][goalsA][goalsB] += dp[round-1][goalsA-1][goalsB-1] * probA * probB;
                }
                dp[round][goalsA][goalsB] += dp[round-1][goalsA][goalsB] * (1 - probA) * (1 - probB);
            }
        }
    }
    for(int i = 0; i < 19; i++)
    {
        for(int j = 0; j < 19; j++)
        {
            if(isPrime(i) || isPrime(j))
            {
                answer += dp[18][i][j];
            }
        }
    }
    std::cout << answer << '\n';
    return 0;
}
