#include <iostream>
typedef long long ll;

int A, B, C;
int fx(int x, int y)
{
    return A * x + B * y + C;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int X1, X2, Y1, Y2;
    std::cin >> A >> B >> C >> X1 >> X2 >> Y1 >> Y2;
    if(1ll * fx(X1, Y1) * fx(X2, Y2) < 0 || 1ll * fx(X1, Y2) * fx(X2, Y1) < 0)
    {
        std::cout << "Poor\n";
    }
    else
    {
        std::cout << "Lucky\n";
    } 
    return 0;
}