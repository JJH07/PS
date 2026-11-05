#include <iostream>
#include <cmath>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout.precision(16);

    int x, y, d, t;
    std::cin >> x >> y >> d >> t;
    double distance = sqrt(x * x + y * y);
    double ans = distance;
    if(d <= t)
    {
        std::cout << distance << '\n';
    }
    else
    {
        double jump_count = distance / d;
        if(jump_count < 1)
        {
            ans = std::min(ans, (double)t * 2);
            ans = std::min(ans, (d - distance) + t);
        }
        else if(jump_count == 1)
        {
            ans = std::min(ans, (double)t);
        }
        else
        {
            jump_count = ceil(jump_count);
            ans = std::min(ans, t * jump_count);
            ans = std::min(ans, (distance - d * (jump_count - 1)) + t * (jump_count - 1));
        }
    }
    std::cout << ans << '\n';
}