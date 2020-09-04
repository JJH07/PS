#include <iostream>
#include <string>
#include <cstring>
#include <vector>

std::string T, P;
int pattern[1000001], T_sz,  P_sz;
std::vector<int> ans;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::getline(std::cin, T);
    std::getline(std::cin, P);
    T_sz = (int)T.length();
    P_sz = (int)P.length();

    int j = 0;
    for(int i = 1; i < P_sz; i++)
    {
        while(j > 0 && P[i] != P[j])
        {
            j = pattern[j - 1];
        }
        if(P[i] == P[j])
        {
            pattern[i] = ++j;
        }
    }
    j = 0;
    for(int i = 0; i < T_sz; i++)
    {
        while(j > 0 && T[i] != P[j])
        {
            j = pattern[j - 1];
        }
        if(T[i] != P[j])
        {
            continue;
        }
        if(j == P_sz - 1)
        {
            ans.push_back(i - P_sz + 2);
            j = pattern[j];
        }
        else
        {
            j++;
        }
    }
    std::cout << ans.size() << '\n';
    for(auto x : ans)
    {
        std::cout << x << '\n';
    }
    return 0;
}