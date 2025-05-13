#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
    fastio;
    int N, k;
    std::vector<int> v;
    std::cin >> N >> k;
    for(int i = 0; i < N; i++){
        int x;
        std::cin >> x;
        v.push_back(x);
    }
    std::sort(v.begin(), v.end());
    std::cout << v[N - k];

    return 0;
}