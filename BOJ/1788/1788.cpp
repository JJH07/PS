#include <cstdlib>
#include <iostream>

constexpr int MOD = 1000000000;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    const int size = std::abs(n);
    int prev = 0, current = 1;
    for(int i = 0; i < size; i++)
    {
        int next = (prev + current) % MOD;
        prev = current;
        current = next;
    }

    int sign = 0;
    if(n != 0)
    {
        sign = n < 0 && n % 2 == 0 ? -1 : 1;
    }
    std::cout << sign << '\n' << prev;
    return 0;
}
