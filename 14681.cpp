#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int x, y;
    std::cin >> x >> y;
    if(x > 0)
    {
        if(y > 0)
        {
            std::cout << '1';
        }
        else
        {
            std::cout << '4';
        }
    }
    else
    {
        if(y > 0)
        {
            std::cout << '2';
        }
        else
        {
            std::cout << '3';
        }
    }

    return 0;
}
