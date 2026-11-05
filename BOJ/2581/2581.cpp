#include <bits/stdc++.h>
int prime[10001];
void init_prime()
{
    std::fill(&prime[2], &prime[10000], 1);
    for(int i = 2; i <= sqrt(10001) + 1; i++)
    {
        if(!prime[i])
        {
            continue;
        }
        for(int j = i + i; j <= 10000; j += i)
        {
            prime[j] = 0;
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M, N, SUM = 0, MIN = 10001;

    init_prime();
    std::cin >> M >> N;
    for(int i = M; i <= N; i++)
    {
        if(MIN == 10001 && prime[i])
        {
            MIN = i; 
        }
        if(prime[i])
        {
            SUM += i;
        }
    }
    if(MIN == 10001)
    {
        std::cout << "-1\n";
    }
    else
    {
        std::cout << SUM << '\n' << MIN << '\n';
    }
    return 0;
}