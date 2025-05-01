#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
    fastio;
    int x[3];
    while(1) {
        std::cin >> x[0] >> x[1] >> x[2];
        if(x[0] == 0 && x[1] == 0 && x[2] == 0) {
            break;
        }
        std::sort(x, x + 3);
        if(x[2] >= x[0] + x[1]) {
            std::cout << "Invalid\n";
        }
        else if(x[0] == x[1] && x[1] == x[2] && x[0] == x[2]) {
            std::cout << "Equilateral\n";
        }
        else if(x[0] == x[1] || x[1] == x[2] || x[0] == x[2]) {
            std::cout << "Isosceles\n";
        }
        else {
            std::cout << "Scalene\n";
        }
    }
    return 0;
}