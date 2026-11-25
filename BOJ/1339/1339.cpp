// Copyright © 2020 진준호. All rights reserved.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<char> letters;
long long weights[26], best;
int digits[26];

void assignDigits(int digit, int assigned, long long score)
{
    if(assigned == static_cast<int>(letters.size()))
    {
        best = std::max(best, score);
        return;
    }
    for(char letter : letters)
    {
        const int index = letter - 'A';
        if(digits[index] != -1)
        {
            continue;
        }
        digits[index] = digit;
        assignDigits(digit - 1, assigned + 1, score + weights[index] * digit);
        digits[index] = -1;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::fill(digits, digits + 26, -1);
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::string word;
        std::cin >> word;
        for(char letter : word)
        {
            const int index = letter - 'A';
            if(digits[index] == -1)
            {
                digits[index] = 0;
                letters.push_back(letter);
            }
        }
        long long place = 1;
        for(auto it = word.rbegin(); it != word.rend(); ++it)
        {
            weights[*it - 'A'] += place;
            place *= 10;
        }
    }
    std::fill(digits, digits + 26, -1);
    assignDigits(9, 0, 0);
    std::cout << best << '\n';
    return 0;
}
