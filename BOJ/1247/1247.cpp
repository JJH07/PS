#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for(int test = 0; test < 3; test++)
    {
        int n;
        std::cin >> n;
        // GCC extension: the sum can exceed the range of long long.
        __int128 sum = 0;
        for(int i = 0; i < n; i++)
        {
            long long value;
            std::cin >> value;
            sum += value;
        }
        std::cout << (sum > 0 ? '+' : sum < 0 ? '-' : '0') << '\n';
    }
    return 0;
}
