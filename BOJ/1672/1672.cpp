// Copyright © 2020 진준호. All rights reserved.

#include <iostream>
#include <string>

constexpr char table[4][4] = {
    {'A', 'C', 'A', 'G'},
    {'C', 'G', 'T', 'A'},
    {'A', 'T', 'C', 'G'},
    {'G', 'A', 'G', 'T'}
};

int baseIndex(char base)
{
    switch(base)
    {
        case 'A': return 0;
        case 'G': return 1;
        case 'C': return 2;
        default: return 3;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int len;
    std::string dna;
    std::cin >> len >> dna;
    char result = dna[len - 1];
    for(int i = len - 2; i >= 0; i--)
    {
        result = table[baseIndex(dna[i])][baseIndex(result)];
    }
    std::cout << result << '\n';
    return 0;
}
