#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int norm[6] = {1, 1, 2, 2, 2, 8};
    for(int i = 0; i < 6; i++)
    {
        int t; 
        std::cin >> t;
        std::cout << norm[i] - t << ' ';
    }
    return 0;
}