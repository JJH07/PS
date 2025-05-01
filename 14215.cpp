#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
    fastio;
    int x[3];
    std::cin >> x[0] >> x[1] >> x[2];
    std::sort(x, x + 3);
    if(x[2] >= x[0] + x[1]) {
        x[2] = x[0] + x[1] - 1;
    }
    std::cout << x[0] + x[1] + x[2];
    return 0;
}