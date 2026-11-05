#include <bits/stdc++.h>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, Grundy = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t;
        std::cin >> t;
        Grundy ^= (t % 2 ? (t / 2 + 1) : (t / 2 - 1));
    }
    std::cout << (Grundy > 0 ? "koosaga\n" : "cubelover\n");
    return 0;
}
