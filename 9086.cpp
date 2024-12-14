#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    while(n--)
    {
        std::string s;
        std::cin >> s;
        std::cout << *s.begin() << *(s.end() - 1) << '\n';
    }
    return 0;
}
