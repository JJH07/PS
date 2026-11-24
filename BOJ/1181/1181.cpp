#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::string> words(n);
    for(auto &word : words)
    {
        std::cin >> word;
    }
    std::sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) {
        return a.size() == b.size() ? a < b : a.size() < b.size();
    });
    words.erase(std::unique(words.begin(), words.end()), words.end());
    for(const auto &word : words)
    {
        std::cout << word << '\n';
    }
    return 0;
}
