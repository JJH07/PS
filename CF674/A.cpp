#include <iostream>
#include <vector>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while(t--)
    {
        int n, x;
        std::cin >> n >> x;
        if(n <= 2)
        {
            std::cout << "1\n";
        }
        else
        {
            n -= 2;
            std::cout << (1 + n / x) + (n % x > 0 ? 1 : 0) << '\n';   
        }
    }
    return 0;
}