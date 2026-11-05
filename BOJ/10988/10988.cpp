#include <bits/stdc++.h>
const int MAX = 101;
char str[MAX];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> str;
    int l = 0, r = std::strlen(str) - 1, ans = 1;
    while(l < r)
    {
        if(str[l++] != str[r--])
        {
            ans = 0;
            break;
        }
    }
    std::cout << ans << '\n';
    return 0;
}