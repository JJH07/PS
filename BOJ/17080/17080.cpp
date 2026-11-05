#include <bits/stdc++.h>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::cout << (n % 4 == 3 ? 2 : 1);
    return 0;
}