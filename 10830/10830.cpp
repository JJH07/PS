#include <iostream>
#include <vector>

typedef long long ll;
typedef std::vector<std::vector<ll>> Matrix;
Matrix operator * (const Matrix &a, const Matrix &b)
{
	int n = a.size();
	Matrix c(n, std::vector<ll>(n));
	for (int i = 0; i < n; i++)
    {
		for (int j = 0; j < n; j++)
        {
			for (int k = 0; k < n; k++)
            {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= 1000;
		}
	}
	return c;
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    ll k;
    std::cin >> n >> k;
	Matrix a(n, std::vector<ll>(n));
	Matrix ans(n, std::vector<ll>(n));
	for (int i = 0; i < n; i++)
    {
		for (int j = 0; j < n; j++)
        {
            std::cin >> a[i][j];
            ans[i][j] = (i == j) ? 1 : 0;
		}
	}

	while (k > 0)
    {
		if (k % 2)
        {
			ans = ans * a;
		}
		a = a * a;
		k /= 2;
	}
	for (int i = 0; i < n; i++)
    {
		for (int j = 0; j < n; j++)
        {
            std::cout << ans[i][j] << ' ';
		}
        std::cout << '\n';
	}
	return 0;
}