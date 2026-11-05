#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
#include <algorithm>
typedef long long ll;
struct Point{
    ll x, y, p, q;
    Point(ll a, ll b) : x(a), y(b), p(1), q(0){}
    bool operator<(const Point &rhs) const{
        if(q * rhs.p != p * rhs.q)
        {
            return q * rhs.p < p * rhs.q;
        }
        if(y != rhs.y)
        {
            return y < rhs.y;
        }
        return x < rhs.x;
    }
};
ll ccw(const Point &A, const Point &B, const Point &C)
{
    ll ret = A.x * B.y + B.x * C.y + C.x * A.y - A.y * B.x - B.y * C.x - C.y * A.x;
    return ret;
}
double get_dist(const Point &A, const Point &B)
{
    double X = A.x - B.x;
    double Y = A.y - B.y;
    return sqrt(X * X + Y * Y); 
}
std::vector<Point> Graham(std::vector<Point> &P, int n)
{
    std::sort(P.begin(), P.end());
    for(int i = 1; i < n; i++)
    {
        P[i].p = P[i].x - P[0].x;
        P[i].q = P[i].y - P[0].y;
    }
    std::sort(P.begin() + 1, P.end());

    std::stack<int> stk;
    stk.push(0);
    stk.push(1);
    int next = 2;
    while(next < n)
    {
        while(stk.size() >= 2)
        {
            int first, second;
            second = stk.top();
            stk.pop();
            first = stk.top();
            if(ccw(P[first], P[second], P[next]) > 0)
            {
                stk.push(second);
                break;
            }
        }
        stk.push(next++);
    }
    std::vector<Point> ret;
    while(!stk.empty())
    {
        ret.push_back(P[stk.top()]);
        stk.pop();
    }
    std::reverse(ret.begin(), ret.end());
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::fixed;
    std::cout.precision(2);

    int TC = 1;
    while(1)
    {
        int n;
        std::cin >> n;
        if(n == 0)
        {
            break;
        }
        std::vector<Point> list;
        for(int i = 0; i < n; i++)
        {
            ll a, b;
            std::cin >> a >> b;
            list.push_back(Point(a, b));
        }
        std::vector<Point> ConvexHull = Graham(list, n);
        int size = (int)ConvexHull.size();
        double ans = 1e10;
        for(int i = 0; i < size; i++)
        {
            int idx1 = i, idx2 = (i + 1) % size;
            double line = get_dist(ConvexHull[idx1], ConvexHull[idx2]);
            double t = 0.0;
            for(int idx3 = 0; idx3 < size; idx3++)
            {
                t = std::max(t, abs(ccw(ConvexHull[idx3], ConvexHull[idx1], ConvexHull[idx2])) / line);
            }
            ans = std::min(ans, t);
        }
        std::cout << "Case " << TC++ << ": " << (ceil(ans * 100) / 100) << '\n';
    }
    return 0;
}