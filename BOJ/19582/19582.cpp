#include<iostream>
typedef long long ll;
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    ll sum = 0, MAX_P = 0;
    int N, FLAG = 1;
	std::cin >> N;
	for (int i = 0; i < N; i++)
    {
        ll X, P;
		std::cin >> X >> P;
		if(sum <= X)
        {
			sum += P;
            MAX_P = std::max(MAX_P, P);
		}
		else if(sum - MAX_P > X || MAX_P < P)
        {
			FLAG--;
		}
		else
        {
			FLAG--;
			sum -= MAX_P;
			sum += P;
		}
		if(FLAG < 0)
        {
			std::cout << "Zzz\n";
            return 0;
		}
	}
	std::cout << "Kkeo-eok\n";
	return 0;
}