#include <bits/stdc++.h>
int n, g, c, k;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t;
        std::cin >> t;
        t == 1 ? ++c : k = t;
        g ^= t;
    }
    if(0 < c && c < n && (c % 2 == 0))
    {
        g = g ^ k ^ 1;
    }
    if(c == n)
    {
        g = (g + 1) % 2;
    }
    std::cout << (g != 0 ? "koosaga\n" : "cubelover\n");
    return 0;
}