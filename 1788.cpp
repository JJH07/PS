#include <bits/stdc++.h>
int fibo[1000001];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
	std::cin >> n;

	fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 1;
	for (int i = 3; i <= abs(n); i++)
	{
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1000000000;
	}

	if(n == 0) std::cout << 0;
	else if(n > 0) std::cout << 1;
	else std::cout << (n % 2 == 0 ? -1 : 1);

	std::cout << '\n' << fibo[abs(n)];
    return 0;
}