#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

int main() {
    fastio;
    std::string str;
    int len;
    std::set<std::string> s;
    std::cin >> str;

    len = str.length();
    for(int i = 0; i < len; i++)
    {
        for(int j = 1; j <= len - i; j++)
        {
            s.insert(str.substr(i, j));
        }
    }
    std::cout << s.size();
    return 0;
}