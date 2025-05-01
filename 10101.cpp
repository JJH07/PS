#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
    fastio;
    int a, b, c;
    std::cin >> a >> b >> c;
    if(a + b + c == 180) {
        if(a == b && b == c && a == c) {
            std::cout << "Equilateral\n";
        }
        else if(a == b || b == c || a == c) {
            std::cout << "Isosceles\n";
        }
        else {
            std::cout << "Scalene\n";
        }
    }
    else {
        std::cout << "Error\n";
    }
    return 0;
}