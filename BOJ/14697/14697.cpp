#include <iostream>
#define MAX 351

int dp[MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int A, B, C, N;
    std::cin >> A >> B >> C >> N;
    dp[0] = 1;
    for(int i = 0; i < N; i++)
    {
        if(dp[i])
        {
            dp[i + A] = 1;
            dp[i + B] = 1;
            dp[i + C] = 1;
        }
    }
    std::cout << dp[N] << '\n';
    return 0;
}