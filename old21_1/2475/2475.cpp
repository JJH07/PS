#include <iostream>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int ans = 0;
    for(int i = 0; i < 5; i++)
    {
        int number;
        std::cin >> number;
        ans += number * number;
    }
    std::cout << ans % 10 << '\n';
    return 0;
}