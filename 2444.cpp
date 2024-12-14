#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    std::cin >> n;
    for(int i = 1; i < n * 2; i++)
    {
        int blank = std::abs(n - i);
        for(int b = 0; b < blank; b++)
        {
            std::cout << ' ';
        }
        for(int s = 0; s < n * 2 - 1 - (blank * 2); s++)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }
    return 0;
}