#include <iostream>
#include <string>

int parse(const std::string &expression)
{
    int number = 0, total = 0;
    bool subtract = false;
    for(std::size_t i = 0; i <= expression.size(); i++)
    {
        const char c = i < expression.size() ? expression[i] : '+';
        if(c >= '0' && c <= '9')
        {
            number = number * 10 + c - '0';
        }
        else
        {
            total += subtract ? -number : number;
            subtract = subtract || c == '-';
            number = 0;
        }
    }
    return total;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string expression;
    std::cin >> expression;
    std::cout << parse(expression) << '\n';
    return 0;
}
