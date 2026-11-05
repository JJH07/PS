#include <bits/stdc++.h>

int grundy[32], check[32];
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int A;
    std::cin >> A;
    for(int n = 1; n <= A; n++)
    {
        grundy[0] = 1;
        grundy[1] = 0;
        for(int i = 2; i <= 31; i++)
        {
            std::memset(check, 0, sizeof(check));
            for(int j = 1; j <= n; j++)
            {
                if(i - j < 0)
                {
                    break;
                }
                check[grundy[i - j]] = 1;
            }
            for(int j = 0; j <= 31; j++)
            {
                if(!check[j])
                {
                    grundy[i] = j;
                    break;
                }
            }
        }
        if(!grundy[31])
        {
            std::cout << n << '\n';
        }
    }
    return 0;
}