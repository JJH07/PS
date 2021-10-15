#include <bits/stdc++.h>

std::string S, T;

int dfs(std::string S, std::string T)
{
    if(S.length() == T.length())
    {
        return S == T;
    }
    if(T.back() == 'A')
    {
        if(dfs(S, T.substr(0, T.length() - 1)))
        {
            return 1;
        }
    }
    if(T.front() == 'B')
    {
        std::reverse(T.begin(), T.end());
        if(dfs(S, T.substr(0, T.length() - 1)))
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> S >> T;
    std::cout << dfs(S, T) << '\n';
    return 0;
}