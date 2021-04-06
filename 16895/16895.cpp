#include <bits/stdc++.h>

int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, list[1000], Grundy = 0, ans = 0;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> list[i];
        Grundy ^= list[i];
    }
    for(int i = 0; i < n; i++)
    {
        if(list[i] > (Grundy ^ list[i]))
        {
            ++ans;
        }
    }
    std::cout << ans << '\n';
    return 0;
}