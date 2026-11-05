#include <bits/stdc++.h>
#define MAX 1041
int Prime[MAX];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    Prime[0] = 1;
    for(int i = 2; i < MAX; i++)
    {
        if(Prime[i])
        {
            continue;
        }
        for(int j = 2; i * j < MAX; j++)
        {
            Prime[i * j] = 1;
        }
    }

    int number = 0;
    std::string str;
    std::cin >> str;
    for(auto c : str)
    {
        if(c >= 'a' && c <= 'z')
        {
            number += c - 'a' + 1;
        }
        else
        {
            number += c - 'A' + 27;
        }
    }
    if(!Prime[number])
    {
        std::cout << "It is a prime word.\n";
    }
    else
    {
        std::cout << "It is not a prime word.\n";
    }
    return 0;
}