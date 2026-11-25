#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;

struct Point{
    int x, y;
    int dx, dy;
    Point(int a, int b) : x(a), y(b), dx(1), dy(0){}

    bool operator<(const Point &rhs) const{
        if(1LL * dy * rhs.dx != 1LL * dx * rhs.dy)
        {
            return 1LL * dy * rhs.dx < 1LL * dx * rhs.dy;
        }
        if(y != rhs.y)
        {
            return y < rhs.y;
        }
        return x < rhs.x;
    }
};
ll ccw(const Point &a, const Point &b, const Point &c)
{
    return 1LL * (a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::vector<Point> points;
    std::cin >> n;
    points.reserve(n);
    for(int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        points.emplace_back(a, b);
    }
    std::sort(points.begin(), points.end());
    for(int i = 1; i < n; i++)
    {
        points[i].dx = points[i].x - points[0].x;
        points[i].dy = points[i].y - points[0].y;
    }
    std::sort(points.begin() + 1, points.end());

    std::vector<int> hull;
    hull.reserve(n);
    hull.push_back(0);
    hull.push_back(1);
    for(int idx = 2; idx < n; idx++)
    {
        while(hull.size() >= 2)
        {
            int first = hull[hull.size() - 2];
            int second = hull.back();
            if(ccw(points[first], points[second], points[idx]) > 0)
            {
                break;
            }
            hull.pop_back();
        }
        hull.push_back(idx);
    }
    std::cout << hull.size() << '\n';
    return 0;
}
