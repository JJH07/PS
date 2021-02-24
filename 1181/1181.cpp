#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int n;
std::vector<std::string> list;
bool comp(const std::string &a, const std::string &b)
{
    if(a.length() == b.length())
    {
        return a < b;
    }
    return a.length() < b.length();
}
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    while(n--)
    {
        std::string t;
        std::cin >> t;
        list.push_back(t);
    }
    std::sort(list.begin(), list.end(), comp);
    list.erase(std::unique(list.begin(), list.end()), list.end());
    for(auto str : list)
    {
        std::cout << str << '\n';
    }
    return 0;
}