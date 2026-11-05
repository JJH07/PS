#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
    fastio;
    int arr[5], sum = 0;
    for(int i = 0; i < 5; i++){
        std::cin >> arr[i];
        sum += arr[i];
    }
    std::sort(arr, arr + 5);
    std::cout << sum / 5 << '\n' << arr[2];
    return 0;
}