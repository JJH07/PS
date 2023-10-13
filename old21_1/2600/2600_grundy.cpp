#include <bits/stdc++.h>
#define MAX 501
int grundy[MAX], check[MAX];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int b[3], n = 5;
    std::cin >> b[0] >> b[1] >> b[2];
    for(int i = 1; i < MAX; i++)
    {
        std::memset(check, 0, sizeof(check));
        for(int bi = 0; bi < 3; bi++)
        {
            if(i - b[bi] >= 0)
            {
                check[grundy[i - b[bi]]] = true;
            }
        }
        int g = 0;
        for(int g_i = 0; g_i < MAX; g_i++)
        {
            if(!check[g_i])
            {
                g = g_i;
                break;
            }
        }
        grundy[i] = g;
    }
    while(n--)
    {
        int k1, k2;
        std::cin >> k1 >> k2;
        std::cout << (grundy[k1] ^ grundy[k2] ? "A\n" : "B\n");
    }
    return 0;
}