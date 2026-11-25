#include <iostream>
#include <string>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, count = 0;
    std::cin >> n;
    for(int number = 666; number <= 10000000; number++)
    {
        std::string text = std::to_string(number);
        if(text.find("666") != std::string::npos)
        {
            ++count;
        }
        if(count == n)
        {
            std::cout << number << '\n';
            break;
        }
    }
    return 0;
}
