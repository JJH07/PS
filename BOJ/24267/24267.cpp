#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
    fastio;
    long long n;
    std::cin >> n;
    std::cout << (1LL * n * (n - 1) * (n - 2) / 6) << "\n3";
    return 0;
}