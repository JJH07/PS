#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int h, m, t;
    std::cin >> h >> m >> t;
    std::cout << (h + (m + t) / 60) % 24 << ' ' << (m + t) % 60;
    return 0;
}
