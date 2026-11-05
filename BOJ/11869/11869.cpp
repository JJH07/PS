#include <bits/stdc++.h>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int m, g = 0;
    std::cin >> m;
    for(int i = 0; i < m; i++)
    {
        int p;
        std::cin >> p;
        g ^= p;
    }
    std::cout << (g ? "koosaga\n" : "cubelover\n");
    return 0;
}