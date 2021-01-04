#include <iostream>
#define MAX 31

int dp[MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i < MAX; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int D, K, A, B;
    std::cin >> D >> K;
    A = dp[D - 2];
    B = dp[D - 1];
    for(int i = 1; i <= K / D; i++)
    {
        if((K - i * A) % B == 0)
        {
            std::cout << i << '\n' << (K - i * A) / B;
            break;
        }
    }
    return 0;
}