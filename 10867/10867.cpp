#include <bits/stdc++.h>

int n;
std::set<int> s;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t;
        std::cin >> t;
        s.insert(t);
    }
    for(auto x : s)
    {
        std::cout << x << ' ';
    }
    return 0;
}