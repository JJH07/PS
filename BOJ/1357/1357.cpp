// Copyright © 2019 진준호. All rights reserved.

#include <iostream>
int reverseDigits(int x)
{
    int result = 0;
    while(x > 0)
    {
        result = result * 10 + x % 10;
        x /= 10;
    }
    return result;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y;
    std::cin >> x >> y;

    std::cout << reverseDigits(reverseDigits(x) + reverseDigits(y)) << '\n';

    return 0;
}
