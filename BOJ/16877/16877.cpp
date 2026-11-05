#include <bits/stdc++.h>
#define MAX 3000001
int Fibo[34], Grundy[MAX], n;
bool check[36];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    Fibo[1] = 1;
    for(int i = 2; i < 34; i++)
    {
        Fibo[i] = Fibo[i - 1] + Fibo[i - 2];
    }
    for(int i = 1; i < MAX; i++)
    {
        std::memset(check, 0, sizeof(check));
        for(int f = 2; f < 34; f++)
        {
            if(Fibo[f] > i)
            {
                break;
            }
            check[Grundy[i - Fibo[f]]] = 1;
        }
        for(int j = 0; j < 36; j++)
        {
            if(!check[j])
            {
                Grundy[i] = j;
                break;
            }
        }
    }
    int n, g = 0;
    std::cin >> n;
    while(n--)
    {
        int t;
        std::cin >> t;
        g ^= Grundy[t];
    }
    std::cout << (g ? "koosaga\n" : "cubelover\n");
}