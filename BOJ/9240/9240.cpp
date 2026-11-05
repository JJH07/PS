#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>

struct Point{
    int x, y, p, q;
    Point(int a, int b) : x(a), y(b), p(1), q(0){}
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
int ccw(const Point &A, const Point &B, const Point &C)
{
    return A.x * B.y + B.x * C.y  + C.x * A.y - A.y * B.x - B.y * C.x - C.y * A.x;
}
double get_dist(const Point &A, const Point &B)
{
    double X = A.x - B.x;
    double Y = A.y - B.y;
    return sqrt(X * X + Y * Y); 
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::fixed;
    std::cout.precision(6);
    int c;
    std::vector<Point> P;
    std::cin >> c;
    for(int i = 0; i < c; i++)
    {
        int a, b;
        std::cin >> a >> b;
        P.push_back(Point(a, b));
    }
    std::sort(P.begin(), P.end());
    for(int i = 1; i < c; i++)
    {
        P[i].p = P[i].x - P[0].x;
        P[i].q = P[i].y - P[0].y;
    }
    std::sort(P.begin() + 1, P.end());

    std::stack<int> stk;
    stk.push(0);
    stk.push(1);
    int idx = 2;
    while(idx < c)
    {
        while(stk.size() >= 2)
        {
            int first, second;
            second = stk.top();
            stk.pop();
            first = stk.top();
            if(ccw(P[first], P[second], P[idx]) > 0)
            {
                stk.push(second);
                break;
            }
        }
        stk.push(idx++);
    }
    std::vector<int> list;
    while(!stk.empty())
    {
        int top = stk.top();
        stk.pop();
        list.push_back(top);
    }
    double ans = 0;
    int sz = (int)list.size();
    for(int i = 0; i < sz - 1; i++)
    {
        for(int j = i + 1; j < sz; j++)
        {
            ans = std::max(ans, get_dist(P[list[i]], P[list[j]]));
        }
    }
    std::cout << ans << '\n';
    return 0;
}