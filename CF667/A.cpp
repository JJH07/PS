#include <iostream>
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int a, b;
        std::cin >> a >> b;
        if(a < b)
        {
            std::swap(a, b);
        }
        int ans = (a - b) / 10 + ((a - b) % 10 > 0 ? 1 : 0);
        std::cout << ans << '\n';
    }
    return 0;
}