#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n[3];
    std::cin >> n[0] >> n[1] >> n[2];
    std::sort(n, n + 3);
    if(n[0] == n[1] && n[1] == n[2])
    {
        std::cout << 10000 + n[0] * 1000;
    }
    else if(n[0] == n[1] || n[0] == n[2])
    {
        std::cout << 1000 + n[0] * 100;
    }
    else if(n[1] == n[2])
    {
        std::cout << 1000 + n[1] * 100;
    }
    else
    {
        std::cout << n[2] * 100;
    }

    return 0;
}
