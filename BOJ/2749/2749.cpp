#include <iostream>

typedef long long ll;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int MOD = 1000000;
    int P = MOD / 10 * 15;
    int fibo[P];
    ll n;
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2; i < P; i++)
    {
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
    }
    std::cin >> n;
    std::cout << fibo[n % P] << '\n';
    return 0;
}