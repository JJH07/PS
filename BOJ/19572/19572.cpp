#include <iostream>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::fixed;
    std::cout.precision(1);
    double ab, ac, bc, tot, a, b, c;
    std::cin >> ab >> ac >> bc;
    tot = (ab + ac + bc) / 2.0;
    a = tot - bc;
    b = tot - ac;
    c = tot - ab;
    if(a <= 0 || b <= 0 || c <= 0)
    {
        std::cout << "-1\n";
    }
    else
    {
        std::cout << "1\n" << a << ' ' << b << ' ' << c << '\n';
    }
    return 0;
}