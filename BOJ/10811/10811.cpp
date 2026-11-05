#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, b[101]; 
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        b[i] = i;
    }
    while(m--)
    {
        int x, y;
        std::cin >> x >> y;
        while(x < y)
        {
            std::swap(b[x], b[y]);
            x++;y--;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        std::cout << b[i] << ' ';
    }
    return 0;
}
