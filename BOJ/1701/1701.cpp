#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

int prefixMax(std::string_view pattern, std::vector<int> &pi)
{
    const int size = pattern.size();
    std::fill(pi.begin(), pi.begin() + size, 0);
    int best = 0, j = 0;
    for(int i = 1; i < size; i++)
    {
        while(j > 0 && pattern[i] != pattern[j])
        {
            j = pi[j - 1];
        }
        if(pattern[i] == pattern[j])
        {
            pi[i] = ++j;
            best = std::max(best, pi[i]);
        }
    }
    return best;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string text;
    std::cin >> text;
    const std::string_view view(text);
    std::vector<int> pi(text.size());
    int answer = 0;
    for(std::size_t start = 0; start < text.size(); start++)
    {
        answer = std::max(answer, prefixMax(view.substr(start), pi));
    }
    std::cout << answer << '\n';
    return 0;
}
