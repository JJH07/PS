#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n, m;
    std::cin >> m >> n;
    while(n--)
    {
        int a, b;
        std::cin >> a >> b;
        m -= a * b;
    }
    std::cout << (m == 0 ? "Yes" : "No");
    return 0;
}
