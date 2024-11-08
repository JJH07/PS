#include<bits/stdc++.h>

int n;
std::vector<int> rope;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t;
        std::cin >> t;
        rope.push_back(t);
    }
    std::sort(rope.begin(), rope.end());

    int w = 0;
    for(int i = 0; i < n; i++)
    {
        w = std::max(w, rope[i] * (n - i));
    }
    std::cout << w;
    return 0;
}