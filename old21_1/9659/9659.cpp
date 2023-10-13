#include <bits/stdc++.h>
typedef long long ll;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    ll n;
    std::cin >> n;
    std::cout << (n % 2 ? "SK\n" : "CY\n");
    return 0;
}