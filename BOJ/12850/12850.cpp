#include <iostream>
#include <vector>
#define MAX 9
#define MOD 1000000007
typedef long long ll;
typedef std::vector<std::vector<ll>> MATRIX;
MATRIX route(9, std::vector<ll>(9));
void connect(int a, int b)
{
    route[a][b] = 1;
    route[b][a] = 1;
}
void init()
{
    connect(1, 2);
    connect(1, 3);
    connect(2, 3);
    connect(2, 4);
    connect(3, 4);
    connect(3, 5);
    connect(4, 5);
    connect(4, 6);
    connect(5, 6);
    connect(5, 8);
    connect(6, 7);
    connect(7, 8);
}
MATRIX operator*(const MATRIX &a, const MATRIX &b)
{
    MATRIX ret(9, std::vector<ll>(9));
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            for(int k = 1; k <= 8; k++)
            {
                ret[i][j] += a[i][k] * b[k][j];
            }
            ret[i][j] %= MOD;
        }
    }
    return ret;
}
MATRIX start(int step)
{
    MATRIX ret(9, std::vector<ll>(9));
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            ret[i][j] = i == j ? 1 : 0;
        }
    }
    while(step > 0)
    {
        if(step % 2)
        {
            ret = ret * route;
        }
        route = route * route;
        step /= 2;
    }
    return ret;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);
    init();
    int d;
    std::cin >> d;
    MATRIX ans = start(d);
    std::cout << ans[1][1] << '\n';
    return 0;
}