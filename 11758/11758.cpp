#include <iostream>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    int x1, x2, x3, y1, y2, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int ccw = x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1;

    std::cout << (ccw > 0 ? "1\n" : (ccw == 0 ? "0\n" :  "-1\n"));

    return 0;
}