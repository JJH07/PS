#include <iostream>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int k, a = 1, b = 0;
    std::cin >> k;
    for(int i = 1; i <= k; i++)
    {
        int na = b;
        int nb = a + b;
        a = na;
        b = nb;
    }
    std::cout << a << ' ' << b << '\n';
    return 0;
}