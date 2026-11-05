#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int ans = INT_MIN, x, y;
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
        {
            int t;
            std::cin >> t;
            if(t > ans)
            {
                ans = t;
                x = i;
                y = j;
            }
        }
    }    
    std::cout << ans << '\n' << x << ' ' << y;
    return 0;
}