#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
typedef long long ll;

struct Point{
    int x, y;
    int p, q;
    Point(int a, int b) : x(a), y(b), p(1), q(0){}

    bool operator<(const Point &rhs) const{
        if(1LL * q * rhs.p != 1LL * p * rhs.q)
        {
            return 1LL * q * rhs.p < 1LL * p * rhs.q;
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
    return 1LL * (A.x * B.y + B.x * C.y + C.x * A.y - A.y * B.x - B.y * C.x - C.y * A.x);
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::vector<Point> P;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        P.push_back(Point(a, b));
    }
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
    int idx = 2;
    while(idx < n)
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
    std::cout << stk.size() << '\n';
    return 0;
}