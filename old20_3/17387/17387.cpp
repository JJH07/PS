#include <iostream>
#include <cmath>
#define X first
#define Y second
typedef long long ll;

std::pair<ll, ll> p[4];
ll ccw(std::pair<ll, ll> a, std::pair<ll, ll> b, std::pair<ll, ll> c)
{
    ll ret = a.X * b.Y + b.X * c.Y + c.X * a.Y - a.Y * b.X - b.Y * c.X - c.Y * a.X;
    return ret == 0 ? 0 : ret > 0 ? 1 : -1;
}
int check(int ccw1, int ccw2)
{
    if(ccw1 == 0 && ccw2 == 0)
    {
        return p[0] <= p[3] && p[2] <= p[1];
    }
    return ccw1 <= 0 && ccw2 <= 0;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    for(int i = 0; i < 4; i++)
    {
        std::cin >> p[i].first >> p[i].second;
    }
    if(p[0] > p[1]) std::swap(p[0], p[1]);
    if(p[2] > p[3]) std::swap(p[2], p[3]);
    ll ccw1 = ccw(p[0], p[1], p[2]) * ccw(p[0], p[1], p[3]);
    ll ccw2 = ccw(p[2], p[3], p[0]) * ccw(p[2], p[3], p[1]);
    std::cout << check(ccw1, ccw2) << '\n';
    return 0;
}