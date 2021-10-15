#include <bits/stdc++.h>

std::string S, T;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> S >> T;
    int S_LEN = S.length(), T_LEN = T.length();
    
    for(int i = T_LEN; i > S_LEN; i--)
    {
        if(T.back() == 'A')
        {
            T.pop_back();
        }
        else
        {
            T.pop_back();
            std::reverse(T.begin(), T.end());
        }
    }
    std::cout << (S == T ? 1 : 0) << '\n';
    return 0;
}