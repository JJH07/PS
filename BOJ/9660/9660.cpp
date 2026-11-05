#include <bits/stdc++.h>
typedef long long ll;

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n;
    std::cin >> n;
    n %= 7;
    std::cout << ((n == 0 || n == 2) ? "CY\n" : "SK\n");
    return 0;
}