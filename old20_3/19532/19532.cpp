#include <iostream>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int a, b, c, d, e, f, x, y;
    std::cin >> a >> b >> c >> d >> e >> f;
    x = (c * e - f * b) / (a * e - d * b);
    y = (c * d - f * a) / (b * d - e * a);
    std::cout << x << ' ' << y << '\n';

    return 0;
}