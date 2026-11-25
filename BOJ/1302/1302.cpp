#include <iostream>
#include <map>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, bestCount = 0;
    std::string bestTitle;
    std::map<std::string, int> counts;
    std::cin >> n;
    while(n--)
    {
        std::string book;
        std::cin >> book;
        const int count = ++counts[book];
        if(count > bestCount || (count == bestCount && book < bestTitle))
        {
            bestCount = count;
            bestTitle = book;
        }
    }
    std::cout << bestTitle << '\n';
    return 0;
}
