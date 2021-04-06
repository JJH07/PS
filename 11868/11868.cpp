#include <bits/stdc++.h>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, g = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t;
        std::cin >> t;
        g ^= t;
    }
    std::cout << (g != 0 ? "koosaga\n" : "cubelover\n");
    return 0;
}