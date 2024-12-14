#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, b[101];
    std::memset(b, 0, sizeof(b));
    std::cin >> n >> m;
    while(m--)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        for(int i = x; i <= y; i++)
        {
            b[i] = z;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        std::cout << b[i] << ' ';
    }
    return 0;
}
