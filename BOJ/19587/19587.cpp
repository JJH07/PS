#include <iostream>
#include <vector>
typedef long long ll;
typedef std::vector<std::vector<ll>> matrix;
const ll MOD = 1e9 + 7;
matrix operator*(const matrix &a, const matrix &b)
{
    int n = a.size();
    matrix c(n, std::vector<ll>(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= MOD;
        }
    }
    return c;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n;
    std::cin >> n;
    matrix ans = {{3, 1}, {1, 3}};
    matrix a = {{2, 1}, {1, 0}};
    while(n > 0)
    {
        if(n % 2 == 1)
        {
            ans = ans * a;
        }
        a = a * a;
        n /= 2;
    }
    std::cout << ans[0][1] << '\n';
    return 0;
}