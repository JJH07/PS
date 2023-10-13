#include <iostream>
#include <cmath>
typedef long long ll;
struct pos{
    ll x, y;
};
ll ccw(pos &a, pos &b, pos &c)
{
    ll ret = a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::fixed;
    std::cout.precision(1);

    int n;
    pos p[10000];
    double ans = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> p[i].x >> p[i].y;
    }
    for(int i = 1; i < n - 1; i++)
    {   
        ans += ccw(p[0], p[i], p[i + 1]);
    }
    std::cout << fabs((double)ans / 2.0) << '\n';
    return 0;
}