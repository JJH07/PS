#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
    fastio;
    int n, x, y, min_x = 10001, min_y = 10001, max_x = -10001, max_y = -10001;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> x >> y;
        min_x = std::min(min_x, x);
        max_x = std::max(max_x, x);
        min_y = std::min(min_y, y);
        max_y = std::max(max_y, y);
    }
    std::cout << (max_x - min_x) * (max_y - min_y);
    return 0;
}