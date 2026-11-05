#include <iostream>

typedef long long ll;
struct pos{
    ll x, y;
};
ll ccw(const pos &X, const pos &Y, const pos &Z)
{
    return X.x * Y.y + Y.x * Z.y + Z.x * X.y - X.y * Y.x - Y.y * Z.x - Z.y * X.x;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    pos p[4];
    for(int i = 0; i < 4; i++)
    {
        std::cin >> p[i].x >> p[i].y;
    }
    ll c1 = ccw(p[0], p[1], p[2]);
    ll c2 = ccw(p[0], p[1], p[3]);
    if((c1 > 0 && c2 < 0) || (c1 < 0 && c2 > 0))
    {
        std::cout << "1\n";
    }
    else
    {
        std::cout << "0\n";
    }
    return 0;
}