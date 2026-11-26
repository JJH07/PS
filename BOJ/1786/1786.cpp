#include <iostream>
#include <string>
#include <vector>

std::vector<int> buildPrefix(const std::string &pattern)
{
    const int size = pattern.size();
    std::vector<int> pi(size, 0);
    int j = 0;
    for(int i = 1; i < size; i++)
    {
        while(j > 0 && pattern[i] != pattern[j])
        {
            j = pi[j - 1];
        }
        if(pattern[i] == pattern[j])
        {
            pi[i] = ++j;
        }
    }
    return pi;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string text, pattern;
    std::getline(std::cin, text);
    std::getline(std::cin, pattern);
    const int textSize = text.size();
    const int patternSize = pattern.size();
    const auto pi = buildPrefix(pattern);
    std::vector<int> matches;

    int j = 0;
    for(int i = 0; i < textSize; i++)
    {
        while(j > 0 && text[i] != pattern[j])
        {
            j = pi[j - 1];
        }
        if(text[i] != pattern[j])
        {
            continue;
        }
        if(j == patternSize - 1)
        {
            matches.push_back(i - patternSize + 2);
            j = pi[j];
        }
        else
        {
            j++;
        }
    }
    std::cout << matches.size() << '\n';
    for(int pos : matches)
    {
        std::cout << pos << '\n';
    }
    return 0;
}
