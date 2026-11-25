#include <iostream>
#include <string>
#include <vector>

using ll = long long;
using Matrix = std::vector<std::vector<ll>>;
constexpr ll MOD = 1000003;
Matrix transition;

Matrix operator*(const Matrix &a, const Matrix &b)
{
    const int size = a.size();
    Matrix result(size, std::vector<ll>(size));
    for(int k = 0; k < size; k++)
    {
        for(int i = 0; i < size; i++)
        {
            if(a[i][k] == 0)
            {
                continue;
            }
            for(int j = 0; j < size; j++)
            {
                if(b[k][j] != 0)
                {
                    result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
    }
    return result;
}

Matrix matrixPower(int exponent)
{
    if(exponent == 1)
    {
        return transition;
    }
    if(exponent % 2)
    {
        return transition * matrixPower(exponent - 1);
    }
    const Matrix half = matrixPower(exponent / 2);
    return half * half;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, start, end, time;
    std::cin >> n >> start >> end >> time;
    transition.resize(5 * n, std::vector<ll>(5 * n));
    for(int i = 0; i < n; i++)
    {
        std::string row;
        std::cin >> row;
        for(int j = 0; j < n; j++)
        {
            const int weight = row[j] - '0';
            if(weight <= 1)
            {
                transition[5 * i][5 * j] = weight;
            }
            else
            {
                transition[5 * i][5 * j + weight - 1] = 1;
                for(int k = weight - 1; k > 0; k--)
                {
                    transition[5 * j + k][5 * j + k - 1] = 1;
                }
            }
        }
    }
    const Matrix result = matrixPower(time);
    std::cout << result[5 * (start - 1)][5 * (end - 1)] << '\n';
    return 0;
}
