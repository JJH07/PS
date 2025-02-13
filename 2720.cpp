#include <bits/stdc++.h>
int coin[4] = {25, 10, 5, 1};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int c;
        std::cin >> c;
        for(int i = 0; i < 4; i++)
        {
            std::cout << c / coin[i] << ' ';
            c %= coin[i];
        }
        std::cout << '\n';
    }
    return 0;
}