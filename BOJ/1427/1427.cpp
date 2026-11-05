#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
    fastio;
    int x;
    std::priority_queue<int> pq;
    std::cin >> x;
    while(x)
    {
        pq.push(x % 10);
        x /= 10;
    }
    while(!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        std::cout << node;
    }
    return 0;
}