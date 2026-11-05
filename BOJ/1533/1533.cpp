#include <iostream>
#include <string>
#include <vector>
#define MAX 11
typedef long long ll;
typedef std::vector<std::vector<ll>> Matrix;
const ll MOD = 1000003;
int N, S, E, T;
Matrix mat;
Matrix operator*(const Matrix &a, const Matrix &b)
{
    Matrix ret(5 * N, std::vector<ll>(5 * N, 0));
    for(int k = 0; k < 5 * N; k++)
    {
        for(int i = 0; i < 5 * N; i++)
        {
            for(int j = 0; j < 5 * N; j++)
            {
                ret[i][j] = (ret[i][j] + (a[i][k] * b[k][j])) % MOD;
            }
        }
    }
    return ret;
}
Matrix Multiply(ll n)
{
    if(n == 1)
    {
        return mat;
    }
    if(n % 2)
    {
        return mat * Multiply(n - 1);
    }
    Matrix t = Multiply(n / 2);
    return t * t;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> S >> E >> T;
    mat.resize(5 * N, std::vector<ll>(5 * N));
    for(int i = 0; i < N; i++)
    {
        std::string t;
        std::cin >> t;
        for(int j = 0; j < N; j++)
        {
            ll c = t[j] - '0';
            if(c <= 1)
            {
                mat[5 * i][5 * j] = c;
            }
            else
            {
                mat[5 * i][5 * j + c - 1] = 1; 
                for(int k = c - 1; k > 0; k--)
                {
                    mat[5 * j + k][5 * j + k - 1] = 1;
                }
            }
        }
    }
    Matrix ans = Multiply(T);
    std::cout << ans[5 * (S - 1)][5 * (E - 1)] << '\n';
    return 0;
}